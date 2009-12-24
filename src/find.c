#include "find.h"

   void
ORCOrigin_Find(int *a,
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

} /* End of ORCOrigin_Find*/
