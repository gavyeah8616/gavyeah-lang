# gavyeah-lang

gavyeah lang is my own lang 

This compiler is written in C++ but hopefully it will get to a point where it can be self-hosted.

## Building

Requires `nasm`, `python3` and `ld` on a Linux operating system.

```bash
git clone https://github.com/gavyeah8616/gavyeah-lang.git
cd gavyeah-lang-master
mkdir build
cmake -S . -B build
cmake --build build
```

Executable will be `gavyeahlang` in the `build/` directory.

#how to use
to use it just run `gavyeahlang <input.gyl>`
