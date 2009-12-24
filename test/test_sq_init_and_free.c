#include "seqlist.h"

int main(void)
{
   int i;
   int error = 0;
   
   ORCSeqList* mylist = NULL;

   printf ("Init my list\n");
   error = ORCSeqList_Init (&mylist);
   if ( error )  goto TERMINATE;
    
   error = ORCSeqList_Output(mylist);
   if ( error )  goto TERMINATE;

   printf ("Free my list\n");
   error = ORCSeqList_Free (&mylist);
   if ( error )  goto TERMINATE;
  
   if ( mylist == NULL )  printf("Free mylist successfully!");
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
