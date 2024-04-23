#include "../simple-utest.h"

register_test(test_something, EXCLUDE | VERBOSE) {
  printf("MOM I WAS CALLED!\n");
  simple_assert_string("Never gonna give you up", "Never gonna let you down");
}

register_test(test_something_else, VERBOSE) {
  simple_assert_int(1, 2);
  simple_assert_int(69, 70);
}

register_test(test_something_true, DEFAULT){
  simple_assert_double(0.0, 0.0);
  simple_assert_string("Hello world", "Hello world");
}
