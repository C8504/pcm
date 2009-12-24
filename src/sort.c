#include "sort.h"

   void
ORCSelect_Sort(int *a,
      int len)
{
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
} /* End of ORCSelect_Sort*/

   void
ORCBubble_Sort(int *a,
      int len)
{
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
} /* End of ORCBubble_Sort*/

