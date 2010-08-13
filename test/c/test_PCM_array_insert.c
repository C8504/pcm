#include "PCMarray.h"

int main(void)
{
   int i;
   int error = 0;

   PCMarray* mylist = NULL;

   printf ("init my list\n");
   CALL(PCMarrayinit (&mylist));

   printf ("insert 1-3 elements");

   for (i = 0; i < 3; ++i) {
      CALL(PCMarrayinsert (mylist, i, i));
   }
   CALL(PCMarrayoutput(mylist));

   printf ("insert 3-5 elements");
   for (i = 3; i < PCMLISTINITSIZE ; ++i) {
      CALL(PCMarrayinsert (mylist, i, i));
   }
   CALL(PCMarrayoutput(mylist));

   printf ("insert 5-10 elements");
   for (i = 5; i < 10; ++i) {
      CALL(PCMarrayinsert (mylist, i, i));
   }
   CALL(PCMarrayoutput(mylist));

   printf ("free my list\n");
   CALL(PCMarrayfree (&mylist));

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:

   PCMcheckerror (error); 
   if ( NULL != mylist )  PCMarrayfree (&mylist);

   return 0;
}
