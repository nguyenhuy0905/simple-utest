#ifndef __SIMPLE_UTEST_H__
#define __SIMPLE_UTEST_H__

/* all the things that shall be used by the end user */

/* maybe this is specific to me. I need to #define and #undef like this
 * for the LSP to not scream at me for the wrong thing */

#define register_test
#undef register_test

#define EXCLUDE
#undef EXCLUDE

#define VERBOSE
#undef VERBOSE

#include "header/.deps.h"
#include "header/assert.h"
#include "header/register.h"

#endif
