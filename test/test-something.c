#include "../simple-utest.h"

register_test(test_something, EXCLUDE | VERBOSE) {
  printf("MOM I WAS CALLED!\n");
}

register_test(test_something_else, DEFAULT) {
  printf("Mom I was called AGAIN!!!\n");
}
