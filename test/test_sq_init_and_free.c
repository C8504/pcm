#include "seqlist.h"

int main(void)
{
   int i;
   int error = 0;
   
   ORCseqlist* mylist = NULL;

   printf ("init my list\n");
   error = ORCseqlistinit (&mylist);
   if ( error )  goto TERMINATE;
    
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
