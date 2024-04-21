#include "header/dead-simple-test.h"

DSTEST_BEGIN_TEST_DEFINE

dstest_begin_declare(test_something);

dstest_assert_int(0 + 1, 1 - 1);
dstest_assert_char('c', 'd');

dstest_end_declare(test_something);

; /* the comma here does nothing but serves as a separator for the code to be
     more readable */

dstest_begin_declare(test_something_else);

dstest_assert_string("Never gonna give you up", "Never gonna let you down");
dstest_assert_string("haha", "haha");

dstest_end_declare(test_something_else);

;

DSTEST_END_TEST_DEFINE

dstest_begin_run();

dstest_run(test_something);

dstest_run(test_something_else);

dstest_end_run();
