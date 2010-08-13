#include "PCMarray.h"

int main(void)
{
   int i, e;
   int error = 0;
   PCMarray* mylist = NULL;

   CALL(PCMarrayinit (&mylist));
   printf ("insert 3 elements\n");
   CALL(PCMarrayinsert (mylist, 0, 8));
   CALL(PCMarrayinsert (mylist, 0, 100));
   CALL(PCMarrayinsert (mylist, 0, 1000));
   PCMarrayoutput (mylist);
   printf ("delete 2th element\n");
   CALL(PCMarraydelete (mylist, 2, &e));
   printf ("The 2th element %d was deleted\n", e);
   CALL(PCMarrayoutput (mylist));
   CALL(PCMarraysort (mylist, mylist->length, 0));
   CALL(PCMarrayoutput (mylist));
   CALL(PCMarrayclear (mylist));
   CALL(PCMarrayoutput (mylist));
   CALL(PCMarrayfree (&mylist));

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != mylist )  PCMarrayfree (&mylist);

   return 0;
}
