#include "ORC.h"
#include "sort.h"
#include "find.h"

typedef  struct {
   int *elem_p;     /* The basic address of list */
   int  length;        /* The length of list */
   int  capacity;      /* The capacity of list*/
} ORCSeqList;

//typedef ORCSeqList* ORCSList;

int ORCSeqList_Init(ORCSeqList **list);
int ORCSeqList_Free(ORCSeqList **list);
int ORCSeqList_Copy (ORCSeqList *list, const int *arr, int count);
int ORCSeqList_Merge (ORCSeqList *des, const ORCSeqList* src);
int ORCSeqList_Clear(ORCSeqList *list);
int ORCSeqList_Insert(ORCSeqList *list, int index, const int elem);
int ORCSeqList_Delete(ORCSeqList *list, int index, int* e);
int ORCSeqList_DeleteR(ORCSeqList *list);
int ORCSeqList_Output(ORCSeqList *list);
int ORCSeqList_Sort(ORCSeqList *list, int length, int alg);
int ORCSeqList_Find(ORCSeqList *list, int length, const int elem, int *index, int alg);
