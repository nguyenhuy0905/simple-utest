#ifndef __DEAD_SIMPLE_TEST_H__
#define __DEAD_SIMPLE_TEST_H__

/* all the necessary includes */
#include "dead-simple-assert.h"
#include "dead-simple-log.h"
#include "dead-simple-register.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* all the things that shall be used by end-user */

/* test results */
typedef enum _test_result {
  TEST_SUCCESS,
  TEST_FAIL,
} test_result;

/* test registration and execution */

#define DSTEST_BEGIN_TEST_DEFINE

#define DSTEST_END_TEST_DEFINE

#define dstest_begin_run() _dstest_begin_run()

#define dstest_end_run() _dstest_end_run()

#define dstest_run(testname) _dstest_run(testname)

#define dstest_begin_define(testname) _dstest_begin_declare(testname)

#define dstest_end_define(testname) _dstest_end_declare(testname)

/* assertion */

#define dstest_assert_char(expected, actual)                                   \
  _dstest_assert_char(expected, actual)

#define dstest_assert_int(expected, actual) _dstest_assert_int(expected, actual)

#define dstest_assert_double(expected, actual)                                 \
  _dstest_assert_double(expected, actual)

#define dstest_assert_float(expected, actual)                                  \
  _dstest_assert_float(expected, actual)

#define dstest_assert_long(expected, actual)                                   \
  _dstest_assert_long(expected, actual)

#define dstest_assert_longlong(expected, actual)                               \
  _dstest_assert_longlong(expected, actual)

#define dstest_assert_string(expected, actual)                                 \
  _dstest_assert_string(expected, actual)

#define dstest_assert_null(actual) _dstest_assert_null(actual)

/* logs */

#define log_fail_info(testname, expected, actual)                              \
  _log_fail_info(testname, expected, actual)

#define log_fail_result(format, expected, actual)                              \
  _log_fail_result(format, expected, actual)

#define log_end_result() _log_end_result()

#endif // !__DEAD_SIMPLE_TEST_H__
