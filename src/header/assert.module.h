#ifndef SIMPLE_UTEST_ASSERT_MODULE_H
#define SIMPLE_UTEST_ASSERT_MODULE_H

#include ".deps.h"
#include "log.h"

/*
 * A list of private methods that is only used to construct assertions.
 * This may be used by end-user to construct their own assertion methods,
 * but should not be used in test files.
 * */

#define log_if_success(comparer, format) \
  if (comparer) {                        \
    if ((verbosity >> 1) & 1) {          \
      log_success(format)                \
    }                                    \
    return;                              \
  }

#define log_if_fail(format)     \
  notify_fail();                \
  if (!(verbosity & 1)) return; \
  log_fail(format);

#define set_up_simple_assert(comparer, format) \
  uint16_t verbosity = get_verbosity();        \
  log_if_success(comparer, format);            \
  log_if_fail(format);

extern void notify_fail(void);

/* I couldn't use expected and actual cuz that's occupied by the log macros */
#define declare_custom_assert(assertname, type) \
  extern void _##assertname(type expect_val, type actual_val, int line);

#endif  // !SIMPLE_UTEST_ASSERT_MODULE_H
