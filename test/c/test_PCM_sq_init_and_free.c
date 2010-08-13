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
   /*    CALL(PCMseqlistinsert (&mylist, 0, 19); */
   /*    if ( error )  goto TERMINATE; */
   PCMseqlist* mylist = NULL;

   CALL(PCMseqlistinit (&mylist));
   CALL(PCMseqlistoutput(mylist));
   CALL(PCMseqlistfree (&mylist));

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != mylist )  PCMseqlistfree (&mylist);

   return 0;
}
