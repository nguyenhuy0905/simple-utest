#include "../simple-utest.h"
#include "../header/assert.h"

#define assert_numeric(type, expected, actual)\
  if(expected != actual)\
    log_fail_general();\
    log_fail_result();\
