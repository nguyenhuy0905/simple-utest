#include "../header/assert.h"
#include "../header/log.h"
#include "../simple-utest.h"
#include <string.h>

#define log_fail_result(format)                                                \
  printf(RED DIM "\t"                                                          \
                 "%s, line %d: "                                               \
                 "Expected " format ", got " format "\n" RESET_ALL,            \
         __func__, line, expected, actual);

void _simple_assert_int(int expected, int actual, int line) {
  if (expected == actual)
    return;

  notify_fail();
  if (!get_verbosity())
    return;
  log_fail_general();
  log_fail_result("%d");
}

void _simple_assert_double(double expected, double actual, int line) {
  if (expected == actual)
    return;
  notify_fail();
  if (!get_verbosity())
    return;
  log_fail_general();
  log_fail_result("%f");
}

void _simple_assert_string(const char *expected, const char *actual, int line) {
  if (strcmp(expected, actual) == 0)
    return;
  notify_fail();
  if (!get_verbosity())
    return;
  log_fail_general();
  log_fail_result("%s");
}
