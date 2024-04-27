#include "../simple-utest.h"

register_test(test_count, VERBOSE) { simple_assert_int(5, 5 + 1); }
