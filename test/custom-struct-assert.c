#include "custom-struct-assert.h"
#include <string.h>

void _custom_assert_cstring_string(c_string *expect_struct, c_string *actual_struct, int line){
  char *expected = get_string(expect_struct);
  char *actual = get_string(actual_struct);

  set_up_simple_assert(strcmp(expected, actual) == 0, "%s");
}
