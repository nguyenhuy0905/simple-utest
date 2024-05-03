#ifndef __CUSTOM_STRUCT_H__
#define __CUSTOM_STRUCT_H__

typedef struct _c_string c_string;

extern c_string *new_string(const char *val);

extern void realloc_string(c_string *cstr, const char *val);

extern char* get_string(c_string *cstr);

extern int get_str_len(c_string *cstr);

extern void string_free(c_string *cstr);

#endif // !__CUSTOM_STRUCT_H__
