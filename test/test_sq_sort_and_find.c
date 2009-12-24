#include "seqlist.h"

int main(void)
{
   int i;
   int error = 0;
   int ind;
   ORCSeqList* mylist = NULL;
   
   printf ("Init my list\n");
   error = ORCSeqList_Init (&mylist);
   if ( error )  goto TERMINATE;
   
   printf ("Unit test one:\n");
   printf ("Insert 4 elements into mylist\n");
   error = ORCSeqList_Insert (mylist, 0, 1);
   if ( error )  goto TERMINATE;
   error = ORCSeqList_Insert (mylist, 1, 10);
   if ( error )  goto TERMINATE;
   error = ORCSeqList_Insert (mylist, 2, 0);
   if ( error )  goto TERMINATE;
   error = ORCSeqList_Insert (mylist, 3, 5);
   if ( error )  goto TERMINATE;
   
   printf ("Find the index of element '5'\n");
   error = ORCSeqList_Find (mylist, mylist->length, 5, &ind, 0);
   if ( error )  goto TERMINATE;
   printf ("Index of 5 is %d\n", ind);
   
   printf ("Output mylist\n");
   ORCSeqList_Output (mylist);
   printf ("Sort mylist\n");
   ORCSeqList_Sort (mylist, mylist->length, 0);
   printf("Output mylist after sort\n");
   ORCSeqList_Output (mylist);
   
  /* printf ("Unit test two:\n");
   error = ORCSeqList_Insert (mylist, 1, 8);
   if ( error )  goto TERMINATE;

   ORCSeqList_Sort (mylist, mylist->length);
   ORCSeqList_Output (mylist);

   error = ORCSeqList_Insert (mylist, 0, 100);
   if ( error )  goto TERMINATE;
   error = ORCSeqList_Insert (mylist, 2, 1000);
   if ( error )  goto TERMINATE;

   ORCSeqList_Sort(mylist, mylist->length);
   ORCSeqList_Output (mylist);

   error = ORCSeqList_Delete (mylist, 3, &e);
   if ( error )  goto TERMINATE;
   
   ORCSeqList_Output (mylist);
   ORCSeqList_Sort (mylist, mylist->length); 
   error = ORCSeqList_Clear (mylist);
   
   ORCSeqList_Output (mylist);
   error = ORCSeqList_Insert (mylist, 0, 100);
   if ( error )  goto TERMINATE;
   error = ORCSeqList_Insert (mylist, 1, 1000);
   ORCSeqList_Output (mylist);
   if ( error )  goto TERMINATE;*/
   
   error = ORCSeqList_Free (&mylist);
   if ( error )  goto TERMINATE;
   
   if ( mylist == NULL )  printf("sqlist free successfully!");
TERMINATE:
   if ( error ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            printf ("ORC Error: %s\n", errorMap[i].str);
         }
      }
      if ( NULL != mylist )  ORCSeqList_Free (&mylist);
   }

   return 0;
}
