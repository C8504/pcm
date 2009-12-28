#include "ORCstring.h"
   int 
ORCdelcharofstring(char * str, 
      int  c)
{
   int i = 0;
   int j = 0;
   int error = 0;

   /*    assert (str != NULL); */
   if ( str == NULL ) {
      error = ORCERRNULLPOINTER;
   }
   else {
      for (i = 0, j = 0; str[i] != '\0'; ++i) {
         if ( str[i] != c )
            str[j++] = str[i];
      }
      str[j] = '\0';
   }

TERMINATE:
   return error;
} /* End of ORCdelcharofstring */

