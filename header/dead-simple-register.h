// TODO: implement test declaration and running
#ifndef __DEAD_SIMPLE_TEST_H__
#error "Only the header dead-simple-test.h shall be included"
/* if you're developing stuff, this error will scream at you, although the thing
 * works totally fine */
#endif // __DEAD_SIMPLE_TEST_H__
#ifndef __DEAD_SIMPLE_REGISTER_H__
#define __DEAD_SIMPLE_REGISTER_H__

#define _dstest_begin_declare(testname)                                        \
  void testname(size_t *n_test, size_t *n_success) {

#define _dstest_end_declare(testname) }

#define _dstest_begin_run()                                                    \
  int main(void) {                                                             \
    size_t n_test = 0;                                                         \
    size_t n_success = 0;

#define _dstest_end_run()                                                      \
  log_end_result();                                                            \
  return EXIT_SUCCESS;                                                         \
  }

#define _dstest_run(testname) testname(&n_test, &n_success);

#endif // !__DEAD_SIMPLE_REGISTER_H__
