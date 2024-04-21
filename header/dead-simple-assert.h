#ifndef __DEAD_SIMPLE_TEST_H__
#error "Only the header dead-simple-test.h shall be included"
/* if you're developing stuff, this error will scream at you, although the thing
 * works totally fine */
#endif // __DEAD_SIMPLE_TEST_H__
#ifndef __DEAD_SIMPLE_ASSERT_H__
#define __DEAD_SIMPLE_ASSERT_H__

// TODO: finish the asserts
#ifndef DSTEST_EXCLUDE_TEST

#define _dstest_assert_numeric(type, expected, actual)                         \
  ++*n_test;                                                                   \
  if (expected == actual) {                                                    \
    ++*n_success;                                                              \
  } else {                                                                     \
    log_fail_info(dstest_assert_##type, expected, actual);

#define _dstest_assert_char(expected, actual)                                  \
  _dstest_assert_numeric(char, expected, actual);                              \
  log_fail_result("%c", expected, actual);                                     \
  }

#define _dstest_assert_int(expected, actual)                                   \
  _dstest_assert_numeric(int, expected, actual);                               \
  log_fail_result("%d", expected, actual);                                     \
  }

#define _dstest_assert_double(expected, actual)                                \
  _dstest_assert_numeric(double, expected, actual);                            \
  log_fail_result("%d", expected, actual);                                     \
  }

#define _dstest_assert_float(expected, actual)                                 \
  _dstest_assert_numeric(float, expected, actual);                             \
  log_fail_result("%f", expected, actual);                                     \
  }

#define _dstest_assert_long(expected, actual)                                  \
  _dstest_assert_numeric(long, expected, actual);                              \
  log_fail_result("%zu", expected, actual);                                    \
  }

#define _dstest_assert_longlong(expected, actual)                              \
  _dstest_assert_numeric(long long, expected, actual);                         \
  log_fail_result("%zu", expected, actual);                                    \
  }

#define _dstest_assert_string(expected, actual)                                \
  ++*n_test;                                                                   \
  if (strcmp(expected, actual) == 0)                                           \
    ++*n_success;                                                              \
  else {                                                                       \
    log_fail_info(dstest_assert_string, expected, actual);                     \
    log_fail_result("%s", expected, actual);                                   \
  }

#define _dstest_assert_null(actual)                                            \
  ++*n_test;                                                                   \
  if (actual == NULL)                                                          \
    ++*n_success;                                                              \
  else {                                                                       \
    log_fail_info(dstest_assert_null, NULL, actual);                           \
  }

#endif // !DSTEST_EXCLUDE_TEST

#ifdef DSTEST_EXCLUDE_TEST

#define _dstest_assert_numeric(type, expected, actual)

#define _dstest_assert_char(expected, actual)

#define _dstest_assert_int(expected, actual)

#define _dstest_assert_double(expected, actual)

#define _dstest_assert_float(expected, actual)

#define _dstest_assert_long(expected, actual)

#define _dstest_assert_longlong(expected, actual)

#endif // DSTEST_EXCLUDE_TEST

#endif // !__DEAD_SIMPLE_ASSERT_H__
