# Simple unit test

> A straightforward unit test utility for the C language

![Output demo](./doc/img/output-demo.jpg)

![Syntax demo](./doc/img/testfile-demo.jpg)

---

## Disclaimer

-

## Requirements

- `clang` or `gcc` or any gcc-compliant C compilers.
- C23. This is important for parameterized tests to work.

  - The utility does utilize the macro `__VA_OPT__`

---

### Installation by building from source

- Install the following:

  - clang; optional
  - CMake
  - Ninja; optional

- On Windows, download these through MSYS2.

- Clone this repo and build:

```bash
git clone https://github.com/nguyenhuy0905/simple-utest.git
cd ./simple-utest
mkdir build && cd build
# remove -DCMAKE_C_COMPILER=clang if you don't have clang
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang ..
cmake --build .
#alternatively, to compile and run the demo code 

```

- Optionally, to compile and run [the demo files](./test/), run this command instead:

```bash
cmake -G Ninja -DTEST_SIMPLE_UTEST=ON \
-DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang ..
cmake --build .
```

---

## Installation by downloading package

> [!IMPORTANT]
> For newer versions, the preferred way is compile from source
>

---

### How to use

- Documentation coming soon. Sorry :(
- To use in your C file/header:

```c
/* simply include it */
#include "simple-utest.h"
```

- Then, when compiling:

```bash
# or gcc
clang -o your-file /path/to/libsimple-utest.a
```

- You can combine a few test files into one test executable
to better utilize the 128 max-test cap.

  - If you choose to do so, make sure that no function has the same name.
  - This is necessary if for some reason, you want
  to write more than about 65000 lines of test.
  - [You can check the demo Makefile to see how to combine tests](./Maketest.example.mk)
  - Or, of course, you can just combine each test file as its own executable.

---

### Plans

- [x] Write some documentation
- [ ] Finish documentation
- [x] Release a binary package
- [x] Allow user-defined assertion
- [x] Implement parameterized tests
- [ ] Let users define more complex test with multiple comparisons in one
- [x] Cross-platform build with CMake
