#include "../simple-utest.h"
#include "../header/entry.h"

#define MAX_TESTS 128

typedef struct test_node test_node;

struct test_node{
  void (*test)();
  const char *filename;
  bool run;
  int line;
};

static test_node reglist[MAX_TESTS];

static int n_test = 0;

void reglist_add(void (*testname)(), const char *filename, int line){
  reglist[n_test].test = testname;
  reglist[n_test].filename = filename;
  reglist[n_test].run = true;
  reglist[n_test].line = line;
  n_test++;
}

void run_all_tests(){
  for(int i = 0; i < n_test; i++){
    reglist[i].test();
  }
}
