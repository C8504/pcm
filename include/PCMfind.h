#ifndef H_FIND
#define H_FIND

#ifdef __cplusplus
extern "C" {
#endif

#include "PCM.h"
   int PCMoriginfind (int *a, int length, const int elem, int *index);
   int PCMbinfind (int *a, int length, const int elem, int *index);

#ifdef __cplusplus
}
#endif

#endif
