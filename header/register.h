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
