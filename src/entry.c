#include "../header/entry.h"
#include "../header/log.h"
#include "../simple-utest.h"

int main(int argc, char *argv[]) {
  printf("\n[" BOLD CYAN "Start test run" RESET_ALL "]\n");

  run_all_tests();

  log_final();

  printf("\n[" BOLD CYAN "End test run" RESET_ALL "]\n");

  return EXIT_SUCCESS;
}
