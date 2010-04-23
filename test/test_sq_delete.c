#include "PCMseqlist.h"

int main(void)
{
   int i, e;
   int error = 0;
   PCMseqlist* mylist = NULL;

   error = PCMseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("insert 3 elements\n");

   error = PCMseqlistinsert (mylist, 0, 8);
   if ( error )  goto TERMINATE;
   error = PCMseqlistinsert (mylist, 0, 100);
   if ( error )  goto TERMINATE;
   error = PCMseqlistinsert (mylist, 0, 1000);
   if ( error )  goto TERMINATE;

   PCMseqlistoutput (mylist);

   printf ("delete 2th element\n");
   error = PCMseqlistdelete (mylist, 2, &e);
   if ( error )  goto TERMINATE;
   printf ("The 2th element %d was deleted\n", e);

   error = PCMseqlistoutput (mylist);
   if ( error )  goto TERMINATE;

   error = PCMseqlistsort (mylist, mylist->length, 0);
   if ( error )  goto TERMINATE;

   error = PCMseqlistoutput (mylist);
   if ( error )  goto TERMINATE;

   error = PCMseqlistclear (mylist);
   if ( error )  goto TERMINATE;

   error = PCMseqlistoutput (mylist);
   if ( error )  goto TERMINATE;

   error = PCMseqlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != mylist )  PCMseqlistfree (&mylist);

   return 0;
}
