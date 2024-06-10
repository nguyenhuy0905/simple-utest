#ifndef CUSTOM_STRUCT_ASSERT_H
#define CUSTOM_STRUCT_ASSERT_H

#include "../header/assert.module.h"
#include "custom-struct.h"

#define custom_assert_cstring_string(expected, actual) \
  _custom_assert_cstring_string(expected, actual, __LINE__)

declare_custom_assert(custom_assert_cstring_string, c_string *)

#endif
