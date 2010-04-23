#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;

   PCMseqlist* mylist = NULL;

   printf ("init my list\n");
   error = PCMseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 1-3 elements");

   for (i = 0; i < 3; ++i) {
      error = PCMseqlistinsert (mylist, i, i);
      if ( error )  goto TERMINATE;
   }
   error = PCMseqlistoutput(mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 3-5 elements");
   for (i = 3; i < PCMLISTINITSIZE ; ++i) {
      error = PCMseqlistinsert (mylist, i, i);
      if ( error )  goto TERMINATE;
   }
   error = PCMseqlistoutput(mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 5-10 elements");
   for (i = 5; i < 10; ++i) {
      error = PCMseqlistinsert (mylist, i, i);
      if ( error )  goto TERMINATE;
   }
   error = PCMseqlistoutput(mylist);
   if ( error )  goto TERMINATE;

   printf ("free my list\n");
   error = PCMseqlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:

   PCMcheckerror (error); 
   if ( NULL != mylist )  PCMseqlistfree (&mylist);

   return 0;
}
