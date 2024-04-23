#ifndef __SIMPLE_UTEST_REGISTER_H__
#define __SIMPLE_UTEST_REGISTER_H__

/*
 * The heart of this utility. Controls everything about a test; from test execution,
 * option handling to log info provision
 * */

/* DO NOT call this function unless you know exactly what you want to do */
extern void reglist_add(void (*testname)(), const char *filename, int line);

/* DO NOT call this function unless you know exactly what you want to do */
extern void reglist_exclude_newest();

#define register_test(testname, ...)                                           \
  void testname();                                                             \
  __attribute__((constructor)) void reg_##testname() {                         \
    reglist_add(testname, __FILE__, __LINE__);                                 \
    __VA_ARGS__                                                                \
  }                                                                            \
  /* define your test */                                                       \
  void testname()

/* options to be passed into register_test() */

#define EXCLUDE reglist_exclude_newest();

#define VERBOSE printf("I WAS ADDED !!!\n");

#endif // !__SIMPLE_UTEST_REGISTER_H__
