#include "ORCsort.h"

void
ORCselectsort(int *a,
              int len)
{
   printf ("CALL ORCselectsort\n");
   int i, j, min;
   int t;

   for (i = 0; i < len; ++i) {
      min = i;
      for (j = i + 1; j < len; ++j) {
         if (a[j] < a[min]) {
            min = j;
         }
      }

      if ( i != min ) {
         t = a[i];
         a[i] = a[min];
         a[min] = t;
      }
   }
} /* End of ORCselectsort*/

void
ORCbubblesort(int *a,
              int len)
{
   printf ("CALL ORCbubblesort\n");
   int i, j;
   int t;

   for (i = 0; i < len; ++i) {
      for (j = i + 1; j < len; ++j) {
         if (a[j] < a[i]) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
         }
      }
   }
} /* End of ORCbubblesort*/

