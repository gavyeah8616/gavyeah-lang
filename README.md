# gavyeah-lang

gavyeah lang is my own lang 

This compiler is written in C++ and python but hopefully it will get to a point where it can be self-hosted.

## Building

Requires `nasm`, `python3` and `ld` on a unix like os such as linux, macos but you can use wsl.

```bash
git clone https://github.com/gavyeah8616/gavyeah-lang.git
cd gavyeah-lang-master
mkdir build
cmake -S . -B build
cmake --build build
```

Executable will be `gavyeahlang` in the `build/` directory.

# how to use
to use it just run `gavyeahlang <input.gyl>`.
to test your program just run 
```bash
./yourprogram.gyl.exe
echo $?
```

# WARING
if you are putting your file in another folder then you NEED to create a folder called src and copy and paste main.py into src

