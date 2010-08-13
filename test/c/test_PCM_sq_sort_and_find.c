#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;
   int ind;
   PCMseqlist* mylist = NULL;

   CALL(PCMseqlistinit (&mylist));
   CALL(PCMseqlistinsert (mylist, 0, 1));
   CALL(PCMseqlistinsert (mylist, 1, 10));
   CALL(PCMseqlistinsert (mylist, 2, 0));
   CALL(PCMseqlistinsert (mylist, 3, 5));
    
   for (i = 0; i < 3; ++i) {
      CALL(PCMseqlistinsert (mylist,i,i*2));
   }

   for (i = 0; i < 3; ++i) {
      CALL(PCMseqlistinsert (mylist,i,i));
   }
   
   PCMseqlistoutput (mylist);
   
   printf ("sort mylist\n");
   enum PCMSORTALG sortalg = PCMALGSORTBUBBLE;
   CALL(PCMseqlistsort (mylist, mylist->length, sortalg));
   printf("output mylist after bubble sort\n");
   PCMseqlistoutput (mylist);

   //enum PCMSORTALG sortalg = PCMALGSORTSELECT;
   //enum PCMSORTALG sortalg = PCMALGSORTQUICK; // use qsort*/
   //enum PCMSORTALG sortalg = PCMALGSORTSHELL;
   //enum PCMSORTALG sortalg = PCMALGSORTINSERT;

   printf ("find the index of element '5'\n");
   enum PCMSEARCHALG findalg = PCMALGORIGINFIND;
   for (i = 0; i < 1000; ++i) {
      CALL(PCMseqlistfind (mylist, mylist->length, 5, &ind, findalg));
   }
   printf ("Index of 5 is %d\n", ind);
   printf ("find the index of element '5'\n");
   findalg = PCMALGBINFIND;
   for (i = 0; i < 1000; ++i) {
      CALL(PCMseqlistfind (mylist, mylist->length, 5, &ind, findalg));
   }
   printf ("Index of 5 is %d\n", ind);



   /* printf ("Unit test two:\n");
      error = PCMseqlistinsert (mylist, 1, 8);
      if ( error )  goto TERMINATE;

      PCMseqlistsort (mylist, mylist->length);
      PCMseqlistoutput (mylist);

      error = PCMseqlistinsert (mylist, 0, 100);
      if ( error )  goto TERMINATE;
      error = PCMseqlistinsert (mylist, 2, 1000);
      if ( error )  goto TERMINATE;

      PCMseqlistsort(mylist, mylist->length);
      PCMseqlistoutput (mylist);

      error = PCMseqlistDelete (mylist, 3, &e);
      if ( error )  goto TERMINATE;

      PCMseqlistoutput (mylist);
      PCMseqlistsort (mylist, mylist->length);
      error = PCMseqlistClear (mylist);

      PCMseqlistoutput (mylist);
      error = PCMseqlistinsert (mylist, 0, 100);
      if ( error )  goto TERMINATE;
      error = PCMseqlistinsert (mylist, 1, 1000);
      PCMseqlistoutput (mylist);
      if ( error )  goto TERMINATE;*/

   CALL(PCMseqlistfree (&mylist));

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
