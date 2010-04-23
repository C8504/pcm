#include "PCMlinkedlist.h"
int testoneelement(void)
{
   int i;
   int error = 0;
   enum PCMPOPTYPE type;

   // Use pointer of list object use the init function and free function to
   // manage memory
   PCMlinkedlist *mylist = NULL;
   error = PCMlinkedlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("mylist = %p, mylist->first = %p, mylist->last = %p\n",
         mylist, mylist->first, mylist->last);

   // append 2 elements
   error = PCMlinkedlistappend (mylist, "a");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistappend (mylist, "A");
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistoutput (mylist, "<append>");

   // pop like stack
   type = PCMPOPSTACK;
   error  = PCMlinkedlistpop (mylist, type);
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistoutput (mylist, "<pop in stack>");
   if ( error )  goto TERMINATE;

   // append 1 elements
   error = PCMlinkedlistappend (mylist, "b");
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistoutput (mylist, "<append>");

   // pop like queue
   type = PCMPOPQUEUE;
   error  = PCMlinkedlistpop (mylist, type);
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistoutput (mylist, "<pop in queue>");
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistclear (mylist);
   if ( error )  goto TERMINATE;
   if ( NULL != mylist )  printf ("list is not NULL after calling clear function!\n\n");

   // append 10 elements again
   for (i = 0; i < 10; ++i) {
      error = PCMlinkedlistappend (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = PCMlinkedlistoutput (mylist, "<append>");
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( NULL == mylist )  printf ("list is NULL after calling free list function!\n\n");

TERMINATE:

   if ( mylist )  PCMlinkedlistfree (&mylist);
   return error;
}

int main(void)
{
   int i;
   int error = 0;

   error = testoneelement();
   if ( error )  goto TERMINATE;

TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
