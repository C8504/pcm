#include "ORCseqlist.h"

int main(void)
{
   int i;
   int error = 0;
   int ind;
   ORCseqlist* mylist = NULL;

   printf ("init my list\n");
   error = ORCseqlistinit (&mylist);
   if ( error )  goto TERMINATE;

   printf ("Unit test one:\n");
   printf ("insert 4 elements into mylist\n");
   error = ORCseqlistinsert (mylist, 0, 1);
   if ( error )  goto TERMINATE;
   error = ORCseqlistinsert (mylist, 1, 10);
   if ( error )  goto TERMINATE;
   error = ORCseqlistinsert (mylist, 2, 0);
   if ( error )  goto TERMINATE;
   error = ORCseqlistinsert (mylist, 3, 5);
   if ( error )  goto TERMINATE;
    
   for (i = 0; i < 30000; ++i) {
      error = ORCseqlistinsert (mylist,i,i*2);
      if ( error )  goto TERMINATE;
   }

   for (i = 0; i < 30000; ++i) {
      error = ORCseqlistinsert (mylist,i,i);
      if ( error )  goto TERMINATE;
   }
   
   printf ("output mylist\n");
/*   ORCseqlistoutput (mylist);*/
   printf ("sort mylist\n");
/*enum ORCSORTALG sortalg = ORCALGSORTBUBBLE;*/
/*enum ORCSORTALG sortalg = ORCALGSORTSELECT;*/
/*enum ORCSORTALG sortalg = ORCALGSORTQUICK; // use qsort*/
   enum ORCSORTALG sortalg = ORCALGSORTSHELL;
   error = ORCseqlistsort (mylist, mylist->length, sortalg);
   if ( error )  goto TERMINATE;
   printf("output mylist after sort\n");
/*   ORCseqlistoutput (mylist);*/

   printf ("find the index of element '5'\n");
   enum ORCSEARCHALG findalg = ORCALGORIGINFIND;
   for (i = 0; i < 1000; ++i) {
      error = ORCseqlistfind (mylist, mylist->length, 5, &ind, findalg);
      if ( error )  goto TERMINATE;
   }
   printf ("Index of 5 is %d\n", ind);
   printf ("find the index of element '5'\n");
   findalg = ORCALGBINFIND;
   for (i = 0; i < 1000; ++i) {
      error = ORCseqlistfind (mylist, mylist->length, 5, &ind, findalg);
      if ( error )  goto TERMINATE;
   }
   printf ("Index of 5 is %d\n", ind);



   /* printf ("Unit test two:\n");
      error = ORCseqlistinsert (mylist, 1, 8);
      if ( error )  goto TERMINATE;

      ORCseqlistsort (mylist, mylist->length);
      ORCseqlistoutput (mylist);

      error = ORCseqlistinsert (mylist, 0, 100);
      if ( error )  goto TERMINATE;
      error = ORCseqlistinsert (mylist, 2, 1000);
      if ( error )  goto TERMINATE;

      ORCseqlistsort(mylist, mylist->length);
      ORCseqlistoutput (mylist);

      error = ORCseqlistDelete (mylist, 3, &e);
      if ( error )  goto TERMINATE;

      ORCseqlistoutput (mylist);
      ORCseqlistsort (mylist, mylist->length);
      error = ORCseqlistClear (mylist);

      ORCseqlistoutput (mylist);
      error = ORCseqlistinsert (mylist, 0, 100);
      if ( error )  goto TERMINATE;
      error = ORCseqlistinsert (mylist, 1, 1000);
      ORCseqlistoutput (mylist);
      if ( error )  goto TERMINATE;*/

   error = ORCseqlistfree (&mylist);
   if ( error )  goto TERMINATE;

   if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
