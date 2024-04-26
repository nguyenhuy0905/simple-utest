#ifndef __SIMPLE_UTEST_ASSERT_MODULE_H__
#define __SIMPLE_UTEST_ASSERT_MODULE_H__

#define log_if_success(comparer, format)                                       \
  if (comparer) {                                                              \
    if ((verbosity >> 1) & 0b1) {                                              \
      log_success(format);                                                     \
    }                                                                          \
    return;                                                                    \
  }

#define log_if_fail(format)                                                    \
  notify_fail();                                                               \
  if (!verbosity)                                                              \
    return;                                                                    \
  log_fail(format);

#define set_up_assert(comparer, format)                                        \
  uint16_t verbosity = get_verbosity();                                        \
  log_if_success(comparer, format);                                            \
  log_if_fail(format);

extern void notify_fail();

#endif // !__SIMPLE_UTEST_ASSERT_MODULE_H__
