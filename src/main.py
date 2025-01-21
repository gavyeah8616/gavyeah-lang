import sys
import os

EXIT_FAILURE = 1
EXIT_SUCCESS = 0

def main():
    os.system("nasm -felf64 " + sys.argv[1] + ".asm")


if __name__ == "__main__":
    main()
