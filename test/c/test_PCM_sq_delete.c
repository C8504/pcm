#include "PCMseqlist.h"

int main(void)
{
   int i, e;
   int error = 0;
   PCMseqlist* mylist = NULL;

   CALL(PCMseqlistinit (&mylist));
   printf ("insert 3 elements\n");
   CALL(PCMseqlistinsert (mylist, 0, 8));
   CALL(PCMseqlistinsert (mylist, 0, 100));
   CALL(PCMseqlistinsert (mylist, 0, 1000));
   PCMseqlistoutput (mylist);
   printf ("delete 2th element\n");
   CALL(PCMseqlistdelete (mylist, 2, &e));
   printf ("The 2th element %d was deleted\n", e);
   CALL(PCMseqlistoutput (mylist));
   CALL(PCMseqlistsort (mylist, mylist->length, 0));
   CALL(PCMseqlistoutput (mylist));
   CALL(PCMseqlistclear (mylist));
   CALL(PCMseqlistoutput (mylist));
   CALL(PCMseqlistfree (&mylist));

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != mylist )  PCMseqlistfree (&mylist);

   return 0;
}
