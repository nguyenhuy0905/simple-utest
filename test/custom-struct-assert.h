#ifndef __CUSTOM_STRUCT_ASSERT_H__
#define __CUSTOM_STRUCT_ASSERT_H__

#include "custom-struct.h"
#include "../header/assert.module.h"

#define custom_assert_cstring_string(expected, actual) _custom_assert_cstring_string(expected, actual, __LINE__)

declare_custom_assert(custom_assert_cstring_string, c_string*);

#endif
