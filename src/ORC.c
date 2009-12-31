#include "ORC.h"
void 
ORCcheckerror (int error) {
   int i = 0;

   if ( error ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            fprintf (stderr, "ORC Error: %s\n", errorMap[i].str);
         }
      }
   }

} /* End of ORCcheckerror*/

void 
ORCswapint (int *i, 
            int *j){
   int temp;

   temp = *i;
   *i = *j;
   *j = temp;
}
