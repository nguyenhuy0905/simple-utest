#include "../simple-utest.h"

register_test(test_something, EXCLUDE | VERBOSE) {
  printf("MOM I WAS CALLED!\n");
  simple_assert_string("Never gonna give you up", "Never gonna let you down");
}

register_test(test_something_else, VERBOSE_FAIL_LOG) {
  simple_assert_int(1, 2);
  simple_assert_int(69, 70);
  simple_assert_int(6, 6);
}

register_test(test_something_true, VERBOSE_SUCCESS_LOG) {
  simple_assert_double(0.0, 0.0);
  simple_assert_string("Hello world", "Hello world");
}
