# Documentation
---
### Demo
- [Click here to see the demo usage](../demo/demo.c)
### Quick-and-dirty start
- Include the header:
```
#include "/path/to/dead-simple-test.h"
```
- Replace '/path/to' with relative or absolute path to the dead-simple-test.h header
- Define tests using:
```
// optional, use this marker to more clearly separate the code
DSTEST_BEGIN_TEST_DEFINE

dstest_begin_define(testname);

/* define your test methods here */

dstest_end_define(testname);

/* define more tests if needed */
// optional, use this marker to more clearly separate the code 
DSTEST_END_TEST_DEFINE
```
- Where `testname` should be replaced with the test function name you want.
- Define your test methods in between `dstest_begin_define(testname);` and `dstest_end_define(testname);` with the `dstest_assert_[type](expected, actual)` method, where `[type]` is the type of `expected` and `actual`.
- At the end of your file, add:
```
dstest_begin_run();

/* run tests */

dstest_end_run();
```
- In between these two "_function_", specify which test you want to run using:
```
dstest_run(testname)
```
- Where `testname` is one of the tests you defined above.
- Compile like you normally would
- To exclude a test `testname`, simply comment out or delete `dstest_run(testname)` 
