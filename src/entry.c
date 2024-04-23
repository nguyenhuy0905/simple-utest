#include "../header/entry.h"
#include "../header/log.h"
#include "../simple-utest.h"

int main(int argc, char *argv[]) {
  run_all_tests();

  log_final();

  return EXIT_SUCCESS;
}
