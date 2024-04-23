# Simple Unit Test
> A straightforward unit test utility for the C language
---
### Disclaimer
- Due to the use of `__attribute__` and `0b` in the code, this is only compatible with compilers that support such features (`gcc`, `clang`, and perhaps more)
- This project is purely for me to learn how to _cook_ something in C.
- Well, technically also a convenient utility for my _other, left-behind_ project.
- If you want something that is as straightforward but is much more featurefull, check out Criterion.
- Due to the design of this utility, running tests concurrently or multi-threadedly is very difficult. You can still spawn threads and run your program however, just be sure that what is passed into assertions is the final result of the multi-thread process
---
### Plans
- [ ] Write some documentation
- [ ] 
