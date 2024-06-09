#include "simple-utest.h"

/* Feature-showcasing */

register_test(test_something, EXCLUDE | VERBOSE) {
  printf("MOM I WAS CALLED!\n");
  simple_assert_string("Never gonna give you up", "Never gonna let you down");
}

register_test(test_something_else, VERBOSE_FAIL_LOG) {
  simple_assert_int(1, 2);
  simple_assert_float(6.6, 6.6, 0.001f);
  simple_assert_double(7.3, 7.4, 0.001f);
  simple_assert_char('c', 'c');
  // just to prove that I have fool-proofed this option :)
  reglist_add(test_something_else, "test_something_else", __FILE__, __LINE__);
}

register_test(test_something_true, VERBOSE_FAIL_LOG) {
  simple_assert_double(0.0, 0.0, 0.001f);
  simple_assert_string("Hello world", "Hello world");
  simple_assert_nonnull((void *)1);
}

register_param_test(test_params, ARGS_LIST(int a, char b), VERBOSE_FAIL_LOG,
                    PARAM_LIST(0, 'a'), PARAM_LIST(1, 'b'),
                    PARAM_LIST(2, 'c')) {
  simple_assert_char(('a' + a), b);
  simple_assert_int((b - 'a'), a);
}
