#include "linkedlist.h"

int main(void)
{
   int i = 0;
   int error = 0;

   ORCLinkedList *mylist = NULL;

   error = ORCLinkedList_Init (&mylist);
   if ( error )  goto TERMINATE;

   error = ORCLinkedList_Output (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORCLinkedList_Free (&mylist);
   if ( error )  goto TERMINATE;

TERMINATE:
   if ( error ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            printf ("ORC Error: %s\n", errorMap[i].str);
         }
      }
   }

   return 0;
}
