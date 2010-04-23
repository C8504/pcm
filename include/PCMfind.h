#ifndef H_FIND
#define H_FIND

#ifdef __cplusplus
extern "C" {
#endif

#include "ORC.h"
   int ORCoriginfind (int *a, int length, const int elem, int *index);
   int ORCbinfind (int *a, int length, const int elem, int *index);

#ifdef __cplusplus
}
#endif

#endif
