#ifndef H_PCM
#define H_PCM

#ifdef __cplusplus
extern "C" {
#endif

#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "PCMstring.h"
#include "PCMconstant.h"
#include "PCMerrormap.h"
   void   PCMcheckerror (int error);
   void   PCMswapchar   (char *arr, int i, int j);
   void** PCMdarraynew  (size_t row, size_t col, size_t size);
   void   PCMdarrayfree (void **arr);
   int    PCMcompare    (const void *x, const void *y);

   void   PCMversion    (char* version);

#ifdef __cplusplus
}
#endif

#endif
