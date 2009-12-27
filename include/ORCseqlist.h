#ifndef H_SEQLIST
#define H_SEQLIST
#include "ORC.h"
#include "ORCsort.h"
#include "ORCfind.h"

typedef  struct {
   int *elemp;     /* The basic address of list */
   int  length;        /* The length of list */
   int  capacity;      /* The capacity of list*/
} ORCseqlist;

typedef ORCseqlist* ORCSList;

int ORCseqlistinit(ORCseqlist **list);
int ORCseqlistfree(ORCseqlist **list);
int ORCseqlistcopy (ORCseqlist *list, const int *arr, int count);
int ORCseqlistmerge (ORCseqlist *des, const ORCseqlist* src);
int ORCseqlistclear(ORCseqlist *list);
int ORCseqlistinsert(ORCseqlist *list, int index, const int elem);
int ORCseqlistdelete(ORCseqlist *list, int index, int* e);
int ORCseqlistdeleteR(ORCseqlist *list);
int ORCseqlistoutput(ORCseqlist *list);
int ORCseqlistsort(ORCseqlist *list, int length, int alg);
int ORCseqlistfind(ORCseqlist *list, int length, const int elem,
                    int *index, int alg);
#endif
