#include "ORC.h"
void ORCcheckerror (int error) {
   int i = 0;

   if ( error ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            printf ("ORC Error: %s\n", errorMap[i].str);
         }
      }
   }

} /* End of ORCcheckerror*/

