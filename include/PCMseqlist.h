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
   } PCMseqlist;

   typedef PCMseqlist* PCMSList;

   int PCMseqlistinit    (PCMseqlist **list);
   int PCMseqlistfree    (PCMseqlist **list);
   int PCMseqlistcopy    (PCMseqlist *list, const int *arr, int count);
   int PCMseqlistmerge   (PCMseqlist *des,  const PCMseqlist* src);
   int PCMseqlistclear   (PCMseqlist *list);
   int PCMseqlistinsert  (PCMseqlist *list, int index, const int elem);
   int PCMseqlistdelete  (PCMseqlist *list, int index, int* e);
   int PCMseqlistdeleteR (PCMseqlist *list);
   int PCMseqlistoutput  (PCMseqlist *list);
   int PCMseqlistsort    (PCMseqlist *list, int length, enum PCMSORTALG alg);
   int PCMseqlistfind    (PCMseqlist *list, int length, const int elem,
                          int *index, enum PCMSEARCHALG alg);
#ifdef __cplusplus
}
#endif

#endif
