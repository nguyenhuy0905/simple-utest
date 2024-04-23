#include "../simple-utest.h"

typedef struct register_list register_list;

typedef struct test_node test_node;

#define test_node_new(testname, filename, linenum)                             \
  ({                                                                           \
    test_node *ret = (test_node *)malloc(sizeof(test_node));                   \
    ret->next = NULL;                                                          \
    ret->filename = filename;                                                  \
    ret->run_this = true;                                                      \
    ret->line_num = linenum;                                                   \
    ret->test = testname;                                                      \
    ret;                                                                       \
  })

struct register_list {
  test_node *head;
  test_node *tail;
  size_t n_test;
};

struct test_node {
  test_node *next;
  bool run_this;
  const char *filename;
  int line_num;
  void (*test)();
};

register_list *reglist;

__attribute__((constructor)) void init(){
  reglist = (register_list*)malloc(sizeof(register_list));
  reglist->head = NULL;
  reglist->tail = NULL;
  reglist->n_test = 0;
}


void reglist_add(void (*testname)(), const char *filename, int line) {
  test_node *new = test_node_new(testname, filename, line);
  if (new == NULL) {
    // TODO: print an error after null allocation
    return;
  }
  if (reglist->head == NULL) {
    reglist->head = new;
    reglist->tail = new;
  } else {
    reglist->tail->next = new;
    reglist->tail = new;
  }
  ++reglist->n_test;
}

void run_all_tests() {
  test_node *curr = reglist->head;
  while (curr != NULL) {
    curr->test();
    curr = curr->next;
  }
  printf("Finished running\n");
}

__attribute__((destructor)) void cleanup() {
  test_node *curr = reglist->head;
  test_node *erase;
  while (curr != NULL) {
    erase = curr;
    curr = curr->next;
    free(erase);
    erase = NULL;
  }
  free(reglist);
  printf("Done freeing\n");
}

