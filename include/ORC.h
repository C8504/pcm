#ifndef H_ORC
#define H_ORC

#ifdef __cplusplus
extern "C" {
#endif

#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "ORCstring.h"
#include "ORCconstant.h"
#include "ORCerrormap.h"
   void ORCcheckerror (int error);
   void ORCswapchar (char *arr, int i, int j);
   void** ORCdarraynew (size_t row, size_t col, size_t size);
   void   ORCdarrayfree (void **arr);
   int    ORCcheckpointer (void *p);

#ifdef __cplusplus
}
#endif

#endif
