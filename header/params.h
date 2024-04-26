#ifndef __SIMPLE_UTEST_PARAMS_H__
#define __SIMPLE_UTEST_PARAMS_H__

#define define_param_list(type, listname, size) type listname[][size] =

#define param_list_size(listname) sizeof(listname) / sizeof(listname[0])

#define loop_param_list(listname)                                              \
  for (int i = 0; i < sizeof(listname) / sizeof(listname[0]); i++)

#define param(listname, index) listname[i][index]

#endif // !__SIMPLE_UTEST_PARAMS_H__
