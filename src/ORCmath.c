#include "ORCmath.h"
   int 
ORCpower(int base,
      int  n,
      long long *result)
{
   long long p = 1LL;
   int error = 0;

   if ( n < 0 ) {
      error = ORCERRNOTVALIDINDEX;
      goto TERMINATE;
   }

   if ( base == 0 ) {
      *result = 0;
      goto TERMINATE;
   }

   for (; n > 0; --n ) {
      p = p * base;
   }

   *result = p; 

TERMINATE:
   return error;
} /* End of ORCpower*/

