#ifndef __DEAD_SIMPLE_TEST_H__
#error "Only the header dead-simple-test.h shall be included"
/* if you're developing stuff, this error will scream at you, although the thing
 * works totally fine */
#endif // __DEAD_SIMPLE_TEST_H__
#ifndef __DEAD_SIMPLE_LOG_H__
#define __DEAD_SIMPLE_LOG_H__

// TODO: add a print log

/* Terminal output colors */
#define LOG_RED "\x1B[31m"
#define LOG_GREEN "\x1B[32m"
#define LOG_YELLOW "\x1b[33m"
#define LOG_BLUE "\x1B[34m"
#define LOG_RESET_COLOR "\x1B[0m"

/* Terminal output styles */

#ifndef DSTEST_OPTION_NO_LOG_FAIL

#define _log_fail_info(testname, expected, actual)                             \
  printf(LOG_RED "\n(Line %d, %s): %s(%s, %s) failed\n" LOG_RESET_COLOR,       \
         __LINE__, __FILE__, #testname, #expected, #actual);

#define _log_fail_result(format, expected, actual)                             \
  printf(LOG_RED "Expected " format ", got " format "\n\n" LOG_RESET_COLOR,    \
         expected, actual);

#endif // !DSTEST_OPTION_LOG_FAIL

#ifdef DSTEST_OPTION_NO_LOG_FAIL

#define _log_fail_info(testname, expected, actual)

#define _log_fail_result(format, expected, actual)

#endif // DEBUG

#define _log_end_result()                                                      \
  printf(LOG_YELLOW "==========%s==========\n\n" LOG_RESET_COLOR,              \
         "TEST RESULT");                                                       \
  printf("%s: " LOG_BLUE "%zu\n\n" LOG_RESET_COLOR, "Number of tests",         \
         n_test);                                                              \
  printf("%s: " LOG_GREEN "%zu\n\n" LOG_RESET_COLOR, "Tests succeeded",        \
         n_success);                                                           \
  printf("%s: " LOG_RED "%zu\n\n" LOG_RESET_COLOR, "Tests failed",             \
         n_test - n_success);

#endif // !__DEAD_SIMPLE_LOG_H__
