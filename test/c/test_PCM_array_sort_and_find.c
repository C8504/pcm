#include "PCMarray.h"

int main(void)
{
   int i;
   int error = 0;
   int ind;
   PCMarray* mylist = NULL;

   CALL(PCMarrayinit (&mylist));
   CALL(PCMarrayinsert (mylist, 0, 1));
   CALL(PCMarrayinsert (mylist, 1, 10));
   CALL(PCMarrayinsert (mylist, 2, 0));
   CALL(PCMarrayinsert (mylist, 3, 5));
    
   for (i = 0; i < 3; ++i) {
      CALL(PCMarrayinsert (mylist,i,i*2));
   }

   for (i = 0; i < 3; ++i) {
      CALL(PCMarrayinsert (mylist,i,i));
   }
   
   PCMarrayoutput (mylist);
   
   printf ("sort mylist\n");
   enum PCMSORTALG sortalg = PCMALGSORTBUBBLE;
   CALL(PCMarraysort (mylist, mylist->length, sortalg));
   printf("output mylist after bubble sort\n");
   PCMarrayoutput (mylist);

   //enum PCMSORTALG sortalg = PCMALGSORTSELECT;
   //enum PCMSORTALG sortalg = PCMALGSORTQUICK; // use qsort*/
   //enum PCMSORTALG sortalg = PCMALGSORTSHELL;
   //enum PCMSORTALG sortalg = PCMALGSORTINSERT;

   printf ("find the index of element '5'\n");
   enum PCMSEARCHALG findalg = PCMALGORIGINFIND;
   for (i = 0; i < 1000; ++i) {
      CALL(PCMarrayfind (mylist, mylist->length, 5, &ind, findalg));
   }
   printf ("Index of 5 is %d\n", ind);
   printf ("find the index of element '5'\n");
   findalg = PCMALGBINFIND;
   for (i = 0; i < 1000; ++i) {
      CALL(PCMarrayfind (mylist, mylist->length, 5, &ind, findalg));
   }
   printf ("Index of 5 is %d\n", ind);



   /* printf ("Unit test two:\n");
      error = PCMarrayinsert (mylist, 1, 8);
      if ( error )  goto TERMINATE;

      PCMarraysort (mylist, mylist->length);
      PCMarrayoutput (mylist);

      error = PCMarrayinsert (mylist, 0, 100);
      if ( error )  goto TERMINATE;
      error = PCMarrayinsert (mylist, 2, 1000);
      if ( error )  goto TERMINATE;

      PCMarraysort(mylist, mylist->length);
      PCMarrayoutput (mylist);

      error = PCMarrayDelete (mylist, 3, &e);
      if ( error )  goto TERMINATE;

      PCMarrayoutput (mylist);
      PCMarraysort (mylist, mylist->length);
      error = PCMarrayClear (mylist);

      PCMarrayoutput (mylist);
      error = PCMarrayinsert (mylist, 0, 100);
      if ( error )  goto TERMINATE;
      error = PCMarrayinsert (mylist, 1, 1000);
      PCMarrayoutput (mylist);
      if ( error )  goto TERMINATE;*/

   CALL(PCMarrayfree (&mylist));

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
