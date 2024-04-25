#include "../header/assert.module.h"
#include "../header/entry.h"
#include "../header/log.h"
#include "../simple-utest.h"
#include <stdint.h>
#include <sys/types.h>

#define MAX_TESTS 128

typedef struct test_node test_node;

#define IS_EXCLUDE(test_pos) ((reglist[test_pos].opt >> 0) & 0b1)
#define IS_VERBOSE(test_pos)                                                   \
  (IS_VERBOSE_FAIL(test_pos) && IS_VERBOSE_SUCCESS(test_pos))
#define IS_VERBOSE_FAIL(test_pos) ((reglist[test_pos].opt >> 1) & 0b1)
#define IS_VERBOSE_SUCCESS(test_pos) ((reglist[test_pos].opt >> 2) & 0b1)

struct test_node {
  void (*test)();
  const char *filename;
  const char *testname;
  // i hope no maniac writes 65,535 lines of test in a single file
  uint16_t line;
  uint16_t opt;
  bool success;
};

/* static variables */

static test_node reglist[MAX_TESTS];

static uint16_t n_test = 0;

static bool end_declare = 0;

static uint16_t n_run = 0;

static uint16_t n_success = 0;

static uint8_t i = 0;
/* Interface definition for entry-point */

void run_all_tests() {
  /* foolproof for the user */
  end_declare = 1;

  uint16_t n_fail = 0;

  for (i = 0; i < n_test; i++) {

    switch (IS_EXCLUDE(i)) {
    case true:
      if (IS_VERBOSE(i))
        printf(STRIKETHROUGH MAGNETA
               "Excluded test %s at line %d, file %s\n" RESET_ALL,
               reglist[i].testname, reglist[i].line, reglist[i].filename);
      continue;
    case false:
      reglist[i].test();
      ++n_run;
      n_success += reglist[i].success;
      break;
    }
  }
}

/* Interface definition for end-user test registration */

void reglist_add(void (*test)(), const char *test_name, const char *filename,
                 uint16_t line) {
  if (end_declare)
    return;
  reglist[n_test].test = test;
  reglist[n_test].filename = filename;
  reglist[n_test].testname = test_name;
  reglist[n_test].line = line;
  reglist[n_test].opt = 0b0;
  reglist[n_test].success = true;
  n_test++;
}

void reglist_config_newest(const uint16_t opt) {
  /* n_test is already incremented when this is called,
   * so to access the "current" test, subtract n by 1 */
  reglist[n_test - 1].opt = (1 - end_declare) * opt;
}

/* Interface definition for log information requests */

void get_summary_info(uint16_t *num_test, uint16_t *num_run,
                      uint16_t *num_success) {
  (*num_test) = n_test;
  (*num_run) = n_run;
  (*num_success) = n_success;
}

void get_current_test_info(const char **test_name, uint16_t *line,
                           const char **file) {
  (*test_name) = reglist[i].testname;
  (*line) = reglist[i].line;
  (*file) = reglist[i].filename;
}

uint16_t get_verbosity() { return (reglist[i].opt >> 1) & 0b11; }

/* Interface definition for assertion results */
void notify_fail() { reglist[i].success = 0; }
