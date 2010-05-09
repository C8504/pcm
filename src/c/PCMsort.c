#include "PCMsort.h"

int
PCMselectsort(int *a,
      int len)
{
   int error = 0;
   int i, j, min;
   int t;

   error = PCMcheckpointer (a);
   if ( error ) {
      printf ("In %s, line %d ;",__FILE__, __LINE__);
      goto TERMINATE;
   }

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
} /* End of PCMselectsort*/

int
PCMbubblesort(int *a,
      int len)
{
   int error = 0;
   int i, j;
   int t;

   error = PCMcheckpointer (a);
   if ( error ) {
      printf ("In %s, line %d ;",__FILE__, __LINE__);
      goto TERMINATE;
   }

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
} /* End of PCMbubblesort*/

int
PCMshellsort(int *a,
      int len)
{
   int error = 0;
   int i, j, gap;
   int temp;

   error = PCMcheckpointer (a);
   if ( error ) {
      printf ("In %s, line %d ;",__FILE__, __LINE__);
      goto TERMINATE;
   }

   while (gap * 3 + 1 <= len) {
      gap=gap * 3 + 1;
   } 
   while (gap > 0) {
      for ( i = gap; i < len; i++ ) {
         j = i - gap;
         temp = a[i];             
         while (( j >= 0 ) && ( a[j] > temp )) {
            a[j + gap] = a[j];
            j = j - gap;
         }
         a[j + gap] = temp;
      }
      gap = ( gap - 1 ) /3;
   }

TERMINATE:
   return error;
} /* End of PCMshellsort */

