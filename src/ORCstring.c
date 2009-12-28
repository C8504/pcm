#include "ORCstring.h"
int
ORCdelcharofstring (char * str,
      int  c) {
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

int
ORCstrlen (const char *str,
      size_t     *len) {
   int i = 0;
   int error = 0;

   if ( str == NULL ) {
      error = ORCERRNULLPOINTER;
   }
   else {
      while ( str[i] != '\0')
         ++i;
   }
   *len = i;

TERMINATE:
   return error;
} /* End of ORCstrlen */
