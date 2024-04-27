#include "../simple-utest.h"

register_test(test_count, VERBOSE) { simple_assert_int(5, 5 + 1); }

register_param_test(test_params, ARGS_LIST(int a, char b), VERBOSE,
                    PARAM_LIST(0, 'a'), PARAM_LIST(1, 'b'),
                    PARAM_LIST(2, 'c')) {
  simple_assert_char(('a' + a), b);
}
