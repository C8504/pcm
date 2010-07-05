#include "PCMmath.h"
int 
PCMpower(int base,
      int  n,
      long long *result)
{
   int error = 0;
   long long p = 1LL;

   if ( n < 0 ) {
      THROW(PCMERRNOTVALIDINDEX);
   }
   else {
      if ( base == 0 ) {
         *result = 0;
      }
      else {
         for (; n > 0; --n ) {
            p = p * base;
         }
         *result = p;
      }
   }

TERMINATE:
   return error;
} /* End of PCMpower*/

