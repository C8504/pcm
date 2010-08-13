#ifndef H_SEQLIST
#define H_SEQLIST

#ifdef __cplusplus
extern "C" {
#endif

#include "PCM.h"
#include "PCMsort.h"
#include "PCMfind.h"

   typedef struct {
      int *elemp;     /* The basic address of list */
      int  length;        /* The length of list */
      int  capacity;      /* The capacity of list*/
   } PCMarray;

   int PCMarrayinit    (PCMarray **list);
   int PCMarrayfree    (PCMarray **list);
   int PCMarraycopy    (PCMarray *list, const int *arr, int count);
   int PCMarraymerge   (PCMarray *des,  const PCMarray* src);
   int PCMarrayclear   (PCMarray *list);
   int PCMarrayinsert  (PCMarray *list, int index, const int elem);
   int PCMarraydelete  (PCMarray *list, int index, int* e);
   int PCMarraydeleteR (PCMarray *list);
   int PCMarrayoutput  (PCMarray *list);
   int PCMarraysort    (PCMarray *list, int length, enum PCMSORTALG alg);
   int PCMarrayfind    (PCMarray *list, int length, const int elem,
                          int *index, enum PCMSEARCHALG alg);
#ifdef __cplusplus
}
#endif

#endif
