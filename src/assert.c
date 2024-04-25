#include "../header/assert.h"
#include "../header/assert.module.h"
#include "../header/log.h"
#include "../simple-utest.h"
#include <string.h>

void _simple_assert_int(int expected, int actual, int line) {
  set_up_assert(expected == actual, "%d");
}

void _simple_assert_double(double expected, double actual, int line) {
  set_up_assert(expected == actual, "%f");
}

void _simple_assert_float(float expected, float actual, int line) {
  set_up_assert(expected == actual, "%f");
}

void _simple_assert_long(long expected, long actual, int line) {
  set_up_assert(expected == actual, "%ld");
}

void _simple_assert_long_long(long long expected, long long actual, int line) {
  set_up_assert(expected == actual, "%lld");
}

void _simple_assert_string(const char *expected, const char *actual, int line) {
  set_up_assert(strcmp(expected, actual) == 0, "%s");
}

void _simple_assert_char(char expected, char actual, int line) {
  set_up_assert(expected == actual, "%c");
}
