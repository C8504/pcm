#include<stdio.h>
#include<limits.h>
#include "PCMmath.h"

int main (void)
{
   int error = 0;
   int i = 0;

   long long r = 0LL;
   int base = 2;
   int index = 62;

   error = PCMpower (base, index, &r);
   if ( error )  goto TERMINATE;

   printf ("PCMpower(%d,%d) == %lld\n", base, index, r);

   base = 100;
   index = -1;
   error = PCMpower (base, index, &r);
   if ( error )  goto TERMINATE;

   printf ("PCMpower(%d,%d) == %lld\n", base, index, r);
TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
