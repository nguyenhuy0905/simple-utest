#include "../simple-utest.h"

register_test(test_something) { printf("MOM I WAS CALLED!\n"); }

register_test(test_something_else){
  printf("Mom I was called AGAIN!!!\n");
}
