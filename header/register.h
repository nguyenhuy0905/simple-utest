#ifndef __SIMPLE_UTEST_H__
#error Only simple-utest.h should be included
/* this is a bit annoying, but just ignore it */
#endif
#ifndef __SIMPLE_UTEST_REGISTER_H__
#define __SIMPLE_UTEST_REGISTER_H__

/* DO NOT call this function unless you know exactly what you want to do */
extern void reglist_add(void (*testname)(), const char *filename, int line);

#define register_test(testname)                                                \
  void testname();                                                             \
  __attribute__((constructor)) void reg_##testname() {                         \
    reglist_add(testname, __FILE__, __LINE__);                                 \
  }                                                                            \
  /* define your test */                                                       \
  void testname()


#endif // !__SIMPLE_UTEST_REGISTER_H__
