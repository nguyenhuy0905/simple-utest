# Simple Unit Test
> A straightforward unit test utility for the C language

![Output demo](./doc/img/output-demo.jpg)

![Syntax demo](./doc/img/testfile-demo.jpg)
---
### Disclaimer
- Due to the use of `__attribute__` and `0b` in the code, this is only compatible with compilers that support such features (`gcc`, `clang`, and perhaps more)
- Well, technically also a convenient utility for my _other, left-behind_ project.
- If you want something that is as straightforward but much more featureful, check out [Criterion](https://github.com/Snaipe/Criterion). This, for now, is meant for my learning this language.
- Due to the design of this utility, running tests concurrently or multi-threadedly is very difficult. You can still spawn threads and run your program however, just be sure that what is passed into assertions is the final result of the multi-thread process
---
### Installation: build from source
- Make sure you have `clang` (version 17 or higher) installed. (Older versions may work but it's not a guarantee) (`gcc` will work as well, but will need a tiny extra step)
- Clone this repo and build
```
git clone https://github.com/nguyenhuy0905/simple-utest.git
cd ./simple-utest
# if you only want to build the library
make 
# or make CC=gcc if you use gcc
# or make CC=gcc OPTS=-g if you want to include debug flags 
# for the library (which is only necessary if you need to test out the library)
```
- Optionally, to run [the demo file](./test/test-something.c), you can instead use the shell script:
```
./run-test.sh
```
---
### Installation: download package
- One day. I promise. One day I will release a package instead.
---
### How to use
- Documentation coming soon. Sorry :(
- To use in your C file/header:
```
/* simply include it */
#include "/path/to/simple-utest/simple-utest.h"
```
- Then, when compiling:
```
# or gcc
clang -o your-file-name your-file-name.c -L/path/to/simple-utest/ -lsimple-utest
```
- To execute the test file (check out [the shell script](./run-test.sh)):
```
LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/path/to/simple-utest/ /path/to/your-file-name
```
---
### Plans
- [ ] Write some documentation
- [ ] Release a binary package
- [ ] Implement user-defined assertion
- [ ] Add inline data "syntax sugar"
