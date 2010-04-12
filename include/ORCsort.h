#ifndef H_SORT
#define H_SORT

#ifdef __cplusplus
extern "C" {
#endif

#include "ORC.h"
   int ORCbubblesort(int *a, int len);
   int ORCselectsort(int *a, int len);
   int ORCshellsort (int *a, int len);

#ifdef __cplusplus
}
#endif

#endif
