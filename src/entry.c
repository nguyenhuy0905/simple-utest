#include "entry.h"
#include ".deps.h"
#include "log.h"

int main() {
  printf("\n[" BOLD CYAN "Start test run" RESET_ALL "]\n");

  run_all_tests();

  log_final();

  printf("\n[" BOLD CYAN "End test run" RESET_ALL "]\n");

  return EXIT_SUCCESS;
}
