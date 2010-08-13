#include "PCMarray.h"

int main(void)
{
   int i;
   int error = 0;
   /*    int arr[10];  */
   /*    PCMarray mylist; */
   /*    mylist.elemp = arr; */
   /*    mylist.length = 1; */
   /*    mylist.capacity = 10; */
   /*    CALL(PCMarrayinsert (&mylist, 0, 19); */
   /*    if ( error )  goto TERMINATE; */
   PCMarray* mylist = NULL;

   CALL(PCMarrayinit (&mylist));
   CALL(PCMarrayoutput(mylist));
   CALL(PCMarrayfree (&mylist));

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != mylist )  PCMarrayfree (&mylist);

   return 0;
}
