#include "ORClinkedlist.h"
int testmanyelements()
{
   int i;
   int error = 0;
   ORClinkedlist* mylist = NULL;

   error = ORClinkedlistinit (&mylist);
   if ( error )  goto TERMINATE;

   // insert  elements here
   error = ORClinkedlistinsert (mylist, 0, "1");
   if ( error )  goto TERMINATE;
   error = ORClinkedlistinsert (mylist, 1, "2");
   if ( error )  goto TERMINATE;
   error = ORClinkedlistinsert (mylist, ORClinkedlistlength(mylist), "end");
   if ( error )  goto TERMINATE;
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // append 10 elements
   for (i = 0; i < 10; ++i) {
      error = ORClinkedlistappend (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // append 10 elements too
   for (i = 0; i < 10; ++i) {
      error = ORClinkedlistappend (mylist, "b");
      if ( error )  goto TERMINATE;
   }
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // insert  elements here
   error = ORClinkedlistinsert (mylist, 1, "3");
   if ( error )  goto TERMINATE;
   error = ORClinkedlistinsert (mylist, 2, "4");
   if ( error )  goto TERMINATE;
   error = ORClinkedlistinsert (mylist, ORClinkedlistlength(mylist), "end");
   if ( error )  goto TERMINATE;
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // pop like stack
   for (i = 0; i < 5; ++i) {
      error  = ORClinkedlistpop (mylist, ORCSTACK);
      if ( error )  goto TERMINATE;
   }
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // pop like queue
   for (i = 0; i < 5; ++i) {
      error  = ORClinkedlistpop (mylist, ORCQUEUE);
      if ( error )  goto TERMINATE;

   }
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // pop like stack
   for (i = 0; i < 10; ++i) {
      error  = ORClinkedlistpop (mylist, ORCSTACK);
      if ( error )  goto TERMINATE;
   }
   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   // insert 10 elements again
   for (i = 0; i < 10; ++i) {
      error = ORClinkedlistappend (mylist, "a");
      if ( error )  goto TERMINATE;
   }

   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( NULL == mylist )  printf ("free list successfully!\n\n");

TERMINATE:

   if ( mylist )  ORClinkedlistfree (&mylist);
   return error;
}

int main(void)
{
   int i;
   int error = 0;

   error = testmanyelements();
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
