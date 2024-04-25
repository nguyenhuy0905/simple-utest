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

void _simple_assert_string(const char *expected, const char *actual, int line) {
  set_up_assert(strcmp(expected, actual) == 0, "%s");
}
