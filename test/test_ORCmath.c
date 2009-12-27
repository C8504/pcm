#include<stdio.h>
#include<limits.h>
#include "ORCmath.h"

int main (void)
{
   int error = 0;
   int i = 0;

   long long r = 0LL;
   int base = 2;
   int index = 62;

   error = ORCpower (base, index, &r);
   if ( error )  goto TERMINATE;

   printf ("ORCpower(%d,%d) == %lld\n", base, index, r);

   base = 100;
   index = -1;
   error = ORCpower (base, index, &r);
   if ( error )  goto TERMINATE;

   printf ("ORCpower(%d,%d) == %lld\n", base, index, r);
TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
