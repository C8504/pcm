#include "seqlist.h"

int main(void)
{
   int i;
   int error = 0;

   ORCseqlist* mylist = NULL;

   printf ("init my list\n");
   error = ORCseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 1-3 elements");

   for (i = 0; i < 3; ++i) {
      error = ORCseqlistinsert (mylist, i, i);
      if ( error )  goto TERMINATE;
   }
   error = ORCseqlistoutput(mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 3-5 elements");
   for (i = 3; i < ORCLISTINITSIZE ; ++i) {
      error = ORCseqlistinsert (mylist, i, i);
      if ( error )  goto TERMINATE;
   }
   error = ORCseqlistoutput(mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 5-10 elements");
   for (i = 5; i < 10; ++i) {
      error = ORCseqlistinsert (mylist, i, i);
      if ( error )  goto TERMINATE;
   }
   error = ORCseqlistoutput(mylist);
   if ( error )  goto TERMINATE;

   printf ("free my list\n");
   error = ORCseqlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:

   ORCcheckerror (error); 
   if ( NULL != mylist )  ORCseqlistfree (&mylist);

   return 0;
}
