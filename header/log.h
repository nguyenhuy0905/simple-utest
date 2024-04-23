#ifndef __SIMPLE_UTEST_LOG_H__
#define __SIMPLE_UTEST_LOG_H__

/*
 * Console output for the utility.
 * Any non-test-specific output is defined in log.c,
 * otherwise it's in, again, register.c
 * */

#define log_final _log_final(n_test)

extern void _log_final(int n_test);

#endif
