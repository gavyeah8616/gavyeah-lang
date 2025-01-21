import sys

EXIT_FAILURE = 1
EXIT_SUCCESS = 0

def main():
    if len(sys.argv) != 2:
        print("Error: Incorrect usage", file=sys.stderr)
        print("Message: use python <input.gyl>", file=sys.stderr)
        return 1  # EXIT_FAILURE equivalent
      
if __name__ == "__main__":
    main()
