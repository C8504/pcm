#include "ORCseqlist.h"

int main(void)
{
   int i;
   int error = 0;
   /*    int arr[10];  */
   /*    ORCseqlist mylist; */
   /*    mylist.elemp = arr; */
   /*    mylist.length = 1; */
   /*    mylist.capacity = 10; */
   /*    error = ORCseqlistinsert (&mylist, 0, 19); */
   /*    if ( error )  goto TERMINATE; */
   ORCseqlist* mylist = NULL;

   printf ("init my list\n");
   error = ORCseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   error = ORCseqlistoutput(&mylist);
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
