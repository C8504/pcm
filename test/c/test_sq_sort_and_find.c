#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;
   int ind;
   PCMseqlist* mylist = NULL;

   printf ("init my list\n");
   error = PCMseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("Unit test one:\n");
   printf ("insert 4 elements into mylist\n");
   error = PCMseqlistinsert (mylist, 0, 1);
   if ( error )  goto TERMINATE;
   error = PCMseqlistinsert (mylist, 1, 10);
   if ( error )  goto TERMINATE;
   error = PCMseqlistinsert (mylist, 2, 0);
   if ( error )  goto TERMINATE;
   error = PCMseqlistinsert (mylist, 3, 5);
   if ( error )  goto TERMINATE;
    
   for (i = 0; i < 30000; ++i) {
      error = PCMseqlistinsert (mylist,i,i*2);
      if ( error )  goto TERMINATE;
   }

   for (i = 0; i < 30000; ++i) {
      error = PCMseqlistinsert (mylist,i,i);
      if ( error )  goto TERMINATE;
   }
   
   printf ("output mylist\n");
/*   PCMseqlistoutput (mylist);*/
   printf ("sort mylist\n");
/*enum PCMSORTALG sortalg = PCMALGSORTBUBBLE;*/
/*enum PCMSORTALG sortalg = PCMALGSORTSELECT;*/
/*enum PCMSORTALG sortalg = PCMALGSORTQUICK; // use qsort*/
   enum PCMSORTALG sortalg = PCMALGSORTSHELL;
   error = PCMseqlistsort (mylist, mylist->length, sortalg);
   if ( error )  goto TERMINATE;
   printf("output mylist after sort\n");
/*   PCMseqlistoutput (mylist);*/

   printf ("find the index of element '5'\n");
   enum PCMSEARCHALG findalg = PCMALGORIGINFIND;
   for (i = 0; i < 1000; ++i) {
      error = PCMseqlistfind (mylist, mylist->length, 5, &ind, findalg);
      if ( error )  goto TERMINATE;
   }
   printf ("Index of 5 is %d\n", ind);
   printf ("find the index of element '5'\n");
   findalg = PCMALGBINFIND;
   for (i = 0; i < 1000; ++i) {
      error = PCMseqlistfind (mylist, mylist->length, 5, &ind, findalg);
      if ( error )  goto TERMINATE;
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

   error = PCMseqlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
