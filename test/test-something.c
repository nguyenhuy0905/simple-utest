#include "../simple-utest.h"

register_test(test_something, EXCLUDE | VERBOSE) {
  printf("MOM I WAS CALLED!\n");
  simple_assert_string("Never gonna give you up", "Never gonna let you down");
}

register_test(test_something_else, VERBOSE_FAIL_LOG) {
  simple_assert_int(1, 2);
  simple_assert_float(6.6, 6.6);
  simple_assert_double(7.3, 7.4);
  simple_assert_char('c', 'c');
  // just to prove that I have fool-proofed this option :)
  reglist_add(test_something_else, "test_something_else", __FILE__, __LINE__);
}

register_test(test_something_true, VERBOSE) {
  simple_assert_double(0.0, 0.0);
  simple_assert_string("Hello world", "Hello world");
  // parameterize
  define_param_list(double, my_double_list,
                    3){{4.2, 4.3, 8.5}, {6.9, 35.1, 42.0}, {-1.0, 1.0, 0.0}};
  loop_param_list(my_double_list) {
    simple_assert_double(param(my_double_list, 2),
                         param(my_double_list, 0) + param(my_double_list, 1));
  }
}
