#include "linkedlist.h"
int test_one_element(void)
{
   int i;
   int error = 0;

   // Use pointer of list object use the _init function and _free function to
   // manage memory
   ORCLinkedList *mylist = NULL;
   error = ORCLinkedList_Init (&mylist);
   if ( error )  goto TERMINATE;

   printf ("mylist = %p, mylist->first = %p, mylist->last = %p\n",
         mylist, mylist->first, mylist->last);

   // append 1 elements
   error = ORCLinkedList_Append (mylist, "a");
   if ( error )  goto TERMINATE;

   error = ORCLinkedList_Output (mylist, ":");

   // pop like stack
   error  = ORCLinkedList_Pop (mylist, ORC_STACK);
   if ( error )  goto TERMINATE;
   error = ORCLinkedList_Output (mylist, ":");
   if ( error )  goto TERMINATE;

   // append 1 elements
   error = ORCLinkedList_Append (mylist, "b");
   if ( error )  goto TERMINATE;

   error = ORCLinkedList_Output (mylist, ":");

   // pop like queue
   error  = ORCLinkedList_Pop (mylist, ORC_QUEUE);
   if ( error )  goto TERMINATE;
   error = ORCLinkedList_Output (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORCLinkedList_Clear (mylist);
   if ( error )  goto TERMINATE;
   if ( NULL != mylist )  printf ("list is not NULL after calling clear function!\n\n");

   // append 10 elements again
   for (i = 0; i < 10; ++i) {
      error = ORCLinkedList_Append (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = ORCLinkedList_Output (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORCLinkedList_Free (&mylist);
   if ( error )  goto TERMINATE;

   if ( NULL == mylist )  printf ("list is NULL after calling free list function!\n\n");

TERMINATE:

   if ( mylist )  ORCLinkedList_Free (&mylist);
   return error;
}

int main(void)
{
   int i;
   int error = 0;

   error = test_one_element();
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
