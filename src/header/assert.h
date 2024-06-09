#ifndef __SIMPLE_UTEST_ASSERT_H__
#define __SIMPLE_UTEST_ASSERT_H__

/*
 * A list of assertion methods available with simple_assert_[datatype] that
 * the end-user can use to write test
 * */

extern void _simple_assert_int(int expected, int actual, int line);

extern void _simple_assert_double(double expected, double actual, double deg, int line);

extern void _simple_assert_string(const char *expected, const char *actual,
                                  int line);

extern void _simple_assert_float(float expected, float actual, float deg, int line);

extern void _simple_assert_long(long expected, long actual, int line);

extern void _simple_assert_long_long(long long expected, long long actual,
                                     int line);

extern void _simple_assert_char(char expected, char actual, int line);

extern void _simple_assert_nonnull(void *expected, int line);

/* Interface with register */

#endif // !__SIMPLE_UTEST_ASSERT_H__