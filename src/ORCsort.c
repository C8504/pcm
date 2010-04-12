#include "ORCsort.h"

   int
ORCselectsort(int *a,
      int len)
{
   int error = 0;
   int i, j, min;
   int t;

   error = ORCcheckpointer (a);
   if ( error )  goto TERMINATE;
   
   for (i = 0; i < len; ++i) {
      min = i;
      for (j = i + 1; j < len; ++j) {
         if ( a[j] < a[min] ) {
            min = j;
         }
      }

      if ( i != min ) {
         t      = a[i];
         a[i]   = a[min];
         a[min] = t;
      }
   }

TERMINATE:
   return error;
} /* End of ORCselectsort*/

   int
ORCbubblesort(int *a,
      int len)
{
   int error = 0;
   int i, j;
   int t;
   
   error = ORCcheckpointer (a);
   if ( error )  goto TERMINATE;

   for (i = 0; i < len; ++i) {
      for (j = i + 1; j < len; ++j) {
         if ( a[j] < a[i] ) {
            t    = a[i];
            a[i] = a[j];
            a[j] = t;
         }
      }
   }

TERMINATE:
   return error;
} /* End of ORCbubblesort*/

/*int*/
/*ORCshellsort(int *a,*/
/*             int len)*/
/*{*/
/*   printf ("CALL ORCbubblesort\n");*/
/*   int error = 0;*/
/*   int i, j;*/
/*   int t;*/
/*   */
/*   error = ORCcheckpointer (a);*/
/*   if ( error )  goto TERMINATE;*/
/**/
/*«¤«shell sort here»¤»*/
/**/
/**/
/*TERMINATE:*/
/*   return error;*/
/*} «¤«End of ORCshellsort»¤»*/
