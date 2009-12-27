#include "ORCseqlist.h"

int main(void)
{
   int i, e;
   int error = 0;
   ORCseqlist* mylist = NULL;

   error = ORCseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 3 elements\n");

   error = ORCseqlistinsert (mylist, 0, 8);
   if ( error )  goto TERMINATE;
   error = ORCseqlistinsert (mylist, 0, 100);
   if ( error )  goto TERMINATE;
   error = ORCseqlistinsert (mylist, 0, 1000);
   if ( error )  goto TERMINATE;

   ORCseqlistoutput (mylist);

   printf ("delete 2th element\n");
   error = ORCseqlistdelete (mylist, 2, &e);
   if ( error )  goto TERMINATE;
   printf ("The 2th element %d was deleted\n", e);

   error = ORCseqlistoutput (mylist);
   if ( error )  goto TERMINATE;

   error = ORCseqlistsort (mylist, mylist->length, 0);
   if ( error )  goto TERMINATE;

   error = ORCseqlistoutput (mylist);
   if ( error )  goto TERMINATE;

   error = ORCseqlistclear (mylist);
   if ( error )  goto TERMINATE;

   error = ORCseqlistoutput (mylist);
   if ( error )  goto TERMINATE;

   error = ORCseqlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   ORCcheckerror (error);
   if ( NULL != mylist )  ORCseqlistfree (&mylist);

   return 0;
}
