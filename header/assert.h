#ifndef __SIMPLE_UTEST_H__
#error Only simple-utest.h should be included
/* this is a bit annoying, but just ignore it */
#endif
#ifndef __SIMPLE_UTEST_ASSERT_H__
#define __SIMPLE_UTEST_ASSERT_H__

/* these includes don't do anything but suppress some wrong and annoying warnings*/
#include <stdbool.h>

extern void simple_assert_int(int expected, int actual);

extern void simple_assert_double(double expected, double actual);

extern void simple_assert_string(const char *expected, const char *actual);

extern void complex_assert_pointer(const void *expected, const void *actual, bool(*comparer)(const void *expected, const void *actual));

#endif // !__SIMPLE_UTEST_ASSERT_H__
