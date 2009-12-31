#include "ORCfind.h"
void
ORCoriginfind(int *a,
              int length,
              const int elem,
              int* index)
{
   printf ("CALL ORCoriginfind\n");
   int i;

   for (i = 0; i < length; ++i) {
      if ( a[i] == elem ) {
         *index = i;
      }
   }

} /* End of ORCoriginfind*/
