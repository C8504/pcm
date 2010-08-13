#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;

   PCMseqlist* mylist = NULL;

   printf ("init my list\n");
   CALL(PCMseqlistinit (&mylist));

   printf ("insert 1-3 elements");

   for (i = 0; i < 3; ++i) {
      CALL(PCMseqlistinsert (mylist, i, i));
   }
   CALL(PCMseqlistoutput(mylist));

   printf ("insert 3-5 elements");
   for (i = 3; i < PCMLISTINITSIZE ; ++i) {
      CALL(PCMseqlistinsert (mylist, i, i));
   }
   CALL(PCMseqlistoutput(mylist));

   printf ("insert 5-10 elements");
   for (i = 5; i < 10; ++i) {
      CALL(PCMseqlistinsert (mylist, i, i));
   }
   CALL(PCMseqlistoutput(mylist));

   printf ("free my list\n");
   CALL(PCMseqlistfree (&mylist));

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:

   PCMcheckerror (error); 
   if ( NULL != mylist )  PCMseqlistfree (&mylist);

   return 0;
}
