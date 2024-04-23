#include "../simple-utest.h"

register_test(test_something, EXCLUDE | VERBOSE) {
  printf("MOM I WAS CALLED!\n");
  simple_assert_string("Never gonna give you up", "Never gonna let you down");
}

register_test(test_something_else, DEFAULT) {
  printf("Mom I was called AGAIN!!!\n");
  simple_assert_int(1, 2);
}
