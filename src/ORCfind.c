#include "find.h"
   void
ORCoriginfind(int *a,
      int length,
      const int elem,
      int* index)
{
   int i;

   for (i = 0; i < length; ++i) {
      if ( a[i] == elem ) {
         *index = i;
      }
   }

} /* End of ORCoriginfind*/
