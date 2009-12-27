#include "linkedlist.h"
int testoneelement(void)
{
   int i;
   int error = 0;

   // Use pointer of list object use the init function and free function to
   // manage memory
   ORClinkedlist *mylist = NULL;
   error = ORClinkedlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("mylist = %p, mylist->first = %p, mylist->last = %p\n",
         mylist, mylist->first, mylist->last);

   // append 1 elements
   error = ORClinkedlistappend (mylist, "a");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistoutput (mylist, ":");

   // pop like stack
   error  = ORClinkedlistpop (mylist, ORCSTACK);
   if ( error )  goto TERMINATE;
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // append 1 elements
   error = ORClinkedlistappend (mylist, "b");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistoutput (mylist, ":");

   // pop like queue
   error  = ORClinkedlistpop (mylist, ORCQUEUE);
   if ( error )  goto TERMINATE;
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistclear (mylist);
   if ( error )  goto TERMINATE;
   if ( NULL != mylist )  printf ("list is not NULL after calling clear function!\n\n");

   // append 10 elements again
   for (i = 0; i < 10; ++i) {
      error = ORClinkedlistappend (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( NULL == mylist )  printf ("list is NULL after calling free list function!\n\n");

TERMINATE:

   if ( mylist )  ORClinkedlistfree (&mylist);
   return error;
}

int main(void)
{
   int i;
   int error = 0;

   error = testoneelement();
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
