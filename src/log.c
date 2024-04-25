#include "../header/log.h"
#include <stdio.h>

void log_final() {
  uint16_t n_test, n_run, n_success;
  get_summary_info(&n_test, &n_run, &n_success);
  printf("\n[" CYAN BOLD "Summary" RESET_ALL "]\n");
  printf("\n\t" BOLD "Total number of tests registered: " BLUE "%d\n" RESET_ALL,
         n_test);
  printf("\n\t" BOLD "Number of tests run: " CYAN "%d\n" RESET_ALL, n_run);
  printf("\n\t" BOLD "Number of tests succeeded: " GREEN "%d\n" RESET_ALL,
         n_success);
  printf("\n\t" BOLD "Number of tests failed: " RED "%d\n" RESET_ALL,
         n_run - n_success);
  printf("\n[" CYAN BOLD "End Summary" RESET_ALL "]\n");
}

void log_fail_general() {
  const char *testname, *file;
  uint16_t line;
  get_current_test_info(&testname, &line, &file);
  printf("\n[" BOLD RED "FAIL" RESET_ALL "] ");
  printf(RED DIM "("
                 "test %s, line %d, file %s"
                 ")\n" RESET_ALL,
         testname, line, file);
}

void log_success_general() {
  const char *testname, *file;
  uint16_t line;
  get_current_test_info(&testname, &line, &file);
  printf("\n[" BOLD GREEN "SUCCESS" RESET_ALL "] ");
  printf(GREEN DIM "("
                   "test %s, line %d, file %s"
                   ")\n" RESET_ALL,
         testname, line, file);
}
