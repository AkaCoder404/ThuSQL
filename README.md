
## Setup
Install antlr4 cpp runtime according to ![this](http://www.cs.sjsu.edu/~mak/tutorials/InstallANTLR4Cpp.pdf) or ![this](https://blog.csdn.net/drutgdh/article/details/122816033) which allows you to `#include "antlr4-runtime.h"`

Run `cmake -S . -B ./build/` to build

Go to the `/build` directory and run `make` and `./src/thusql ../tests/1.txt` to run the first test case.

