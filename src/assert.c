#include "assert.h"

#include <string.h>

#include ".deps.h"
#include "assert.module.h"
#include "log.h"

void _simple_assert_int(int expected, int actual, int line) {
  set_up_simple_assert(expected == actual, "%d");
}

void _simple_assert_double(double expected, double actual, double deg,
                           int line) {
  set_up_simple_assert(
      (expected - actual) <= deg && (expected - actual) >= -deg, "%f");
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

void _simple_assert_nonnull(void *actual, int line) {
  uint16_t verbosity = get_verbosity();
  if (actual == NULL) {
    notify_fail();
    if (verbosity & 1) {
      log_fail_general();
      printf(RED DIM
             "\t"
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
  if ((verbosity >> 1) & 1) {
    log_success_general();
    printf(GREEN DIM
           "\t"
           "%s(void*), line %d\n" RESET_ALL,
           __func__, line);
  }
}

void _simple_assert_true(bool actual, int line) {
  uint16_t verbosity = get_verbosity();
  if (!actual) {
    notify_fail();
    if (verbosity & 1) {
      log_fail_general();
      printf(RED DIM
             "\t"
             "%s, line %d: "
             "Expected "
             "true"
             ", got "
             "false"
             "\n" RESET_ALL,
             __func__, line);
    }
    return;
  }
  if ((verbosity >> 1) & 1) {
    log_success_general();
    printf(GREEN DIM
           "\t"
           "%s(bool), line %d\n" RESET_ALL,
           __func__, line);
  }
}
