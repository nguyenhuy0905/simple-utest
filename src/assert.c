#include "../header/assert.h"
#include "../header/.deps.h"
#include "../header/assert.module.h"
#include "../header/log.h"
#include <string.h>

void _simple_assert_int(int expected, int actual, int line) {
  set_up_simple_assert(expected == actual, "%d");
}

void _simple_assert_double(double expected, double actual, double deg,
                           int line) {
  set_up_simple_assert((expected - actual) <= deg, "%f");
}

void _simple_assert_float(float expected, float actual, float deg, int line) {
  set_up_simple_assert((expected - actual) <= deg, "%f");
}

void _simple_assert_long(long expected, long actual, int line) {
  set_up_simple_assert(expected == actual, "%ld");
}

void _simple_assert_long_long(long long expected, long long actual, int line) {
  set_up_simple_assert(expected == actual, "%lld");
}

void _simple_assert_string(const char *expected, const char *actual, int line) {
  set_up_simple_assert(strcmp(expected, actual) == 0, "%s");
}

void _simple_assert_char(char expected, char actual, int line) {
  set_up_simple_assert(expected == actual, "%c");
}

void _simple_assert_nonnull(void *expected, int line) {
  uint16_t verbosity = get_verbosity();
  if (expected == NULL) {
    notify_fail();
    if (verbosity & 0b1) {
      log_fail_general();
      printf(RED DIM "\t"
                     "%s, line %d: "
                     "Expected "
                     "non-NULL"
                     ", got "
                     "NULL"
                     "\n" RESET_ALL,
             __func__, line);
    }
    return;
  }
  if ((verbosity >> 1) & 0b1) {
    log_success_general();
    printf(GREEN DIM "\t"
                     "%s(void*), line %d\n" RESET_ALL,
           __func__, __LINE__);
  }
}
