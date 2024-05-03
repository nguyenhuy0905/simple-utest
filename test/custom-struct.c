#include "custom-struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _c_string{
  char *str;
  int len;
};

c_string *new_string(const char* val){
  c_string *new_instance = (c_string*)malloc(sizeof(c_string));
  if(new_instance == NULL){
    printf("String allocation error\n");
    return NULL;
  }
  new_instance->len = strlen(val);
  new_instance->str = (char*)malloc(new_instance->len + 1);
  strncpy(new_instance->str, val, new_instance->len);
  new_instance->str[new_instance->len] = '\0';
  return new_instance;
}

void realloc_string(c_string *cstr, const char *val){
  cstr->len = strlen(val);
  cstr->str = (char*)realloc(cstr->str, cstr->len + 1); 
  strncpy(cstr->str, val, cstr->len);
  cstr->str[cstr->len] = '\0';
}

char *get_string(c_string *cstr){
  return cstr->str;
}

int get_str_len(c_string *cstr){
  return cstr->len;
}

void string_free(c_string *cstr){
  free(cstr->str);
  cstr->str = NULL;
  free(cstr);
  cstr = NULL;
}
