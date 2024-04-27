#ifndef __SIMPLE_UTEST_PARAMS_H__
#define __SIMPLE_UTEST_PARAMS_H__

#define PARAM_LIST(...) \
  { __VA_ARGS__ }

#define simple_parameterize(p_listname, type, n_col, paramlist) \
  type p_listname[][n_col] = paramlist;                         \
  for (int i = 0; i < sizeof(p_listname) / sizeof(p_listname[0]); i++)

#define params(listname) listname[i]

#define list_size(listname) sizeof((int[])listname)

#endif  // !__SIMPLE_UTEST_PARAMS_H__
