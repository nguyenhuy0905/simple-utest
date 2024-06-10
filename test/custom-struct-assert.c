#include "custom-struct-assert.h"

#include <string.h>

void _custom_assert_cstring_string(c_string *expect_val,
                                    c_string *actual_val, int line) {
  char *expected = get_string(expect_val);
  char *actual = get_string(actual_val);

  set_up_simple_assert(strcmp(expected, actual) == 0, "%s");
}
