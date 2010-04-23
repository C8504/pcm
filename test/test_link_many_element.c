#include "PCMlinkedlist.h"
int testmanyelements()
{
   int i;
   int error = 0;
   enum PCMPOPTYPE type;
   PCMlinkedlist* mylist = NULL;

   error = PCMlinkedlistinit (&mylist);
   if ( error )  goto TERMINATE;

   // insert  elements here
   error = PCMlinkedlistinsert (mylist, 0, "1");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistinsert (mylist, 1, "2");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistinsert (mylist, PCMlinkedlistlength(mylist), "end");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // append 10 elements
   for (i = 0; i < 10; ++i) {
      error = PCMlinkedlistappend (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // append 10 elements too
   for (i = 0; i < 10; ++i) {
      error = PCMlinkedlistappend (mylist, "b");
      if ( error )  goto TERMINATE;
   }
   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // insert  elements here
   error = PCMlinkedlistinsert (mylist, 1, "3");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistinsert (mylist, 2, "4");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistinsert (mylist, PCMlinkedlistlength(mylist), "end");
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // pop like stack
   type = PCMPOPSTACK;
   for (i = 0; i < 5; ++i) {
      error  = PCMlinkedlistpop (mylist, type);
      if ( error )  goto TERMINATE;
   }
   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // pop like queue
   type = PCMPOPQUEUE;
   for (i = 0; i < 5; ++i) {
      error  = PCMlinkedlistpop (mylist, type);
      if ( error )  goto TERMINATE;

   }
   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // pop like stack
   type = PCMPOPQUEUE;
   for (i = 0; i < 10; ++i) {
      error  = PCMlinkedlistpop (mylist, type);
      if ( error )  goto TERMINATE;
   }
   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // insert 10 elements again
   for (i = 0; i < 10; ++i) {
      error = PCMlinkedlistappend (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = PCMlinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( NULL == mylist )  printf ("free list successfully!\n\n");

TERMINATE:

   if ( mylist )  PCMlinkedlistfree (&mylist);
   return error;
}

int main(void)
{
   int i;
   int error = 0;

   error = testmanyelements();
   if ( error )  goto TERMINATE;

TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
