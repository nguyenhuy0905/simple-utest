#include "../simple-utest.h"

/* This file is mainly here to show how to combine 2 test files into one */

register_test(test_count, EXCLUDE | VERBOSE) { simple_assert_int(5, 5 + 1); }
