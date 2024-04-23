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
