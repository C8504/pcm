#include "ORC.h"
void 
ORCcheckerror (int error) {
   int i = 0;

   if ( error > ORCERRSTART) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            fprintf (stderr, "ORC Error: %s\n", errorMap[i].str);
         }
      }
   }
   else if (error != 0 && error < ORCERRSTART) {
      fprintf (stderr, "errno = %d, ORC Error(by system function calling): %s\n", 
               error, strerror (error));
   }

} /* End of ORCcheckerror*/

void 
ORCswapchar (char* arr,
         int i, 
         int j){
   int temp;

   temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}
