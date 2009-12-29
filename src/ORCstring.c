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

int 
ORCstrtrim (char *str) {
   int error = 0;
   size_t n;
   int i = 0;

   error = ORCstrlen(str, &n);
   if ( error )  goto TERMINATE;

   if ( n > 0 ) {
      for (i = n-1; (i >= 0) && (str[i] == ' ' || str[i] == '\t'); --i); 
      if ( i >= -1 ) {
         ++i;
         str[i] = '\0';
      }
   }

TERMINATE:
   return error;
} /* End of ORCstrtrim*/

int
ORCstreverse (char *str) {
   int error = 0;
   size_t n;
   int i = 0;
   int j = 0;
   int temp = 0;

   error = ORCstrlen (str, &n);
   if ( error )  goto TERMINATE;

   if ( n > 0 ) {
      j = n - 1;
      /* Can not use ORCswapint here */
      while (i < j) {
         temp   = str[i];
         str[i] = str[j];
         str[j] = temp;
         ++i;
         --j;
      }
   }

TERMINATE:
   return error;
}
