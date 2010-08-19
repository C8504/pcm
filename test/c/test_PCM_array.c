#include "PCMarray.h"

// unit test framework in C
typedef void (*UnitTestFunction)(void);

static void run_test(UnitTestFunction test)
{
   test();
}

void run_tests(UnitTestFunction *tests)
{
   int i = 0;
   
   for (i = 0; tests[i] != NULL; ++i) {
      run_test(tests[i]);
   }
}



void test_PCM_array_init_and_free(void)
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

}

void test_PCM_array_delete(void)
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

}

void test_PCM_array_inout(void) 
{
   int error = 0;
   int num = 0;

   int max = 0;
   int count = 0;
   int sum = 0;

   PCMarray *list = NULL;
   CALL(PCMarrayinit(&list));

   printf("Please input intergers:\n");

   while (1 == scanf ("%d", &num)) {
      CALL(PCMarrayinsert(list, count, num));
      sum += num;

      if ( 0 == count ) {
         max = num;
      }
      else {
         if ( max < num ) {
            max = num;
         }
      }
      count++;
   }

   CALL(PCMarraysort (list, list->length, PCMALGSORTSELECT));

   //CALL(PCMarraysort (list, list->length, PCMALGSORTBUBBLE));
   //if ( error )  goto TERMINATE;

   // CALL(PCMarraysort (list, list->length, 0));
   //if ( error )  goto TERMINATE;

   CALL(PCMarrayoutput (list));

   CALL(PCMarrayfree (&list));

   printf ("You have input %d integers\n", count);
   printf ("The max one is %d\n"         , max);
   printf ("The sum of them is %d\n"     , sum);

TERMINATE:
   PCMcheckerror(error);
   if ( NULL != list )   PCMarrayfree(&list);
}

void test_PCM_array_insert(void) 
{
   int i;
   int error = 0;

   PCMarray* mylist = NULL;

   printf ("init my list\n");
   CALL(PCMarrayinit (&mylist));

   printf ("insert 1-3 elements");

   for (i = 0; i < 3; ++i) {
      CALL(PCMarrayinsert (mylist, i, i));
   }
   CALL(PCMarrayoutput(mylist));

   printf ("insert 3-5 elements");
   for (i = 3; i < PCMLISTINITSIZE ; ++i) {
      CALL(PCMarrayinsert (mylist, i, i));
   }
   CALL(PCMarrayoutput(mylist));

   printf ("insert 5-10 elements");
   for (i = 5; i < 10; ++i) {
      CALL(PCMarrayinsert (mylist, i, i));
   }
   CALL(PCMarrayoutput(mylist));

   printf ("free my list\n");
   CALL(PCMarrayfree (&mylist));

   if ( mylist == NULL )  printf("free mylist successfully!");
TERMINATE:

   PCMcheckerror (error); 
   if ( NULL != mylist )  PCMarrayfree (&mylist);

}

void test_PCM_array_merge(void) 
{
   int i;
   int error = 0;

   int a[5] = {1, 3, 3, 7, 7};
   int b[5] = {1, 3, 6, 6, 10};

   PCMarray* odd = NULL;
   PCMarray* even = NULL;

   CALL(PCMarrayinit (&odd));
   CALL(PCMarrayinit (&even));
   CALL(PCMarraycopy (odd, a, 5));
   CALL(PCMarraycopy (even, b, 5));
   CALL(PCMarraymerge (odd, even));
   CALL(PCMarraydeleteR (odd));
   CALL(PCMarrayoutput (odd));
   CALL(PCMarrayoutput (even));
   CALL(PCMarrayfree (&odd));
   CALL(PCMarrayfree (&even));

   if ( even == NULL )  printf ("free even successfully!\n");
   if ( odd == NULL  )  printf ("free odd successfully!\n");
TERMINATE:
   PCMcheckerror (error);
}

void test_PCM_array_sort_and_find(void) 
{
   int i;
   int error = 0;
   int ind;
   PCMarray* mylist = NULL;

   printf("sort_and_find\n");
   CALL(PCMarrayinit (&mylist));
   printf("after init\n");
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
}



static UnitTestFunction tests[] = {
   test_PCM_array_init_and_free,
   test_PCM_array_delete,
   //test_PCM_array_inout,
   test_PCM_array_insert,
   test_PCM_array_sort_and_find,
   test_PCM_array_merge,
   NULL
};

int main()
{
   
  run_tests(tests); 
   
  return 0;
}
