#include "../header/assert.h"
#include "../header/log.h"
#include "../simple-utest.h"
#include <string.h>

#define log_fail_result(format, expected, actual)                              \
  printf(RED DIM "\tExpected " format ", got " format "\n" RESET_ALL,          \
         expected, actual);

void simple_assert_int(int expected, int actual) {
  if (expected == actual)
    return;
  
  notify_fail();
  if(!get_verbosity())
    return;
  log_fail_general();
  log_fail_result("%d", expected, actual);
}

void simple_assert_double(double expected, double actual) {
  if (expected == actual)
    return;
  notify_fail();
  if(!get_verbosity())
    return;
  log_fail_general();
  log_fail_result("%f", expected, actual);
}

void simple_assert_string(const char *expected, const char *actual) {
  if (strcmp(expected, actual) == 0)
    return;
  notify_fail();
  if(!get_verbosity())
    return;
  log_fail_general();
  log_fail_result("%s", expected, actual);
}
