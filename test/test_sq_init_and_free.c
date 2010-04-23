#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;
   /*    int arr[10];  */
   /*    PCMseqlist mylist; */
   /*    mylist.elemp = arr; */
   /*    mylist.length = 1; */
   /*    mylist.capacity = 10; */
   /*    error = PCMseqlistinsert (&mylist, 0, 19); */
   /*    if ( error )  goto TERMINATE; */
   PCMseqlist* mylist = NULL;

   printf ("init my list\n");
   error = PCMseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

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
