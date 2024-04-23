#include "../header/entry.h"
#include "../header/log.h"
#include "../simple-utest.h"
#include <stdint.h>

#define MAX_TESTS 128

typedef struct test_node test_node;

/* doesn't actually do anything other than being a "lookup table" */
enum lookup_opt {
  OPT_DEFAULT = 0b00000000, // simply, none of the options below
  OPT_EXCLUDE = 0b00000001, // registered in bit #16
  OPT_VERBOSE = 0b00000010, // registered in bit #15
};

#define IS_EXCLUDE(test_pos) ((reglist[test_pos].opt >> 0) & 0b1)
#define IS_VERBOSE(test_pos) ((reglist[test_pos].opt >> 1) & 0b1)

struct test_node {
  void (*test)();
  const char *filename;
  uint16_t line; // i hope no maniac writes 65,535 lines of test
  uint8_t opt;
};

static test_node reglist[MAX_TESTS];

static int n_test = 0;

static bool end_declare = 0;

void reglist_add(void (*testname)(), const char *filename, uint16_t line) {
  reglist[n_test].test = testname;
  reglist[n_test].filename = filename;
  reglist[n_test].line = line;
  reglist[n_test].opt = 0b0;
  n_test++;
}

void reglist_config_newest(const uint16_t opt) {
  /* n_test is already incremented when this is called,
   * so to access the "current" test, subtract n by 1 */
  reglist[n_test - 1].opt |= (1 - end_declare) * opt;
}

void run_all_tests() {
  /* foolproof for the user */
  end_declare = 1;

  for (int i = 0; i < n_test; i++) {
    if (!IS_EXCLUDE(i))
      reglist[i].test();
  }
}
