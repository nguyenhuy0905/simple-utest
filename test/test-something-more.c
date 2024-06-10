#include <string.h>
#include "simple-utest.h"
#include "custom-struct.h"
#include "custom-struct-assert.h"

/* This file is mainly here to show how to combine 2 test files into one */

register_test(test_count, EXCLUDE | VERBOSE) { simple_assert_int(5, 5 + 1); }

register_test(test_string, VERBOSE_FAIL_LOG){
  c_string *test_inst = new_string("Never gonna give you up");

  simple_assert_string("Never gonna give you up", get_string(test_inst)); // should be true

  custom_assert_cstring_string(test_inst, test_inst);
  simple_assert_string(get_string(test_inst), get_string(test_inst));

  simple_assert_int(strlen("Never gonna give you up\0"), get_str_len(test_inst)); // should ALSO be true

  string_free(test_inst);
}
