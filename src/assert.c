#include "../header/assert.h"
#include "../header/log.h"
#include "../simple-utest.h"
#include <string.h>

void _simple_assert_int(int expected, int actual, int line) {
  uint16_t verbosity = get_verbosity();
  if (expected == actual) {
    if ((verbosity >> 1) & 0b1)
      log_success("%d");
    return;
  }
  notify_fail();
  if (!verbosity)
    return;
  log_fail("%d");
}

void _simple_assert_double(double expected, double actual, int line) {
  uint16_t verbosity = get_verbosity();
  if (expected == actual) {
    if ((verbosity >> 1) & 0b1)
      log_success("%f");
    return;
  }
  notify_fail();
  if (!verbosity)
    return;
  log_fail("%f");
}

void _simple_assert_string(const char *expected, const char *actual, int line) {
  uint16_t verbosity = get_verbosity();
  if (strcmp(expected, actual) == 0) {
    if ((verbosity >> 1) & 0b1)
      log_success("%s");
    return;
  }
  notify_fail();
  if (!verbosity)
    return;
  log_fail("%s");
}
