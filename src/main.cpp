#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <vector>

#include "generation.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Error: Incorrect usage" << std::endl;
        std::cerr << "Message: use ./gavyeahlang (or ./build/gavyeahlang) <input.gyl>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    Parser parser(std::move(tokens));
    std::optional<NodeProg> prog = parser.parse_prog();

    if (!prog.has_value()) {
        std::cerr << "Error: Invalid program" << std::endl;
        exit(EXIT_FAILURE);
    }

    {
        Generator generator(prog.value());
        std::string output_filename = std::string(argv[1]) + ".asm";
        std::fstream file(output_filename, std::ios::out);
        file << generator.gen_prog();
    }

    system("python3 ./src/main.py ./test.gyl");
    std::string command = "ld -o " + std::string(argv[1]) + ".exe test.gyl.o";
    system(command.c_str());

    return EXIT_SUCCESS;
}
