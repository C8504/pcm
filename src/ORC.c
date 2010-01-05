#include "ORC.h"
void
ORCcheckerror (int error) {
   int i = 0;

   if ( error > ORCERRSTART &&
         error < ORCERREND     ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            printf ("ORC Error: %s\n", errorMap[i].str);
         }
      }
   }
   else if ( error != 0 ) {
      /*       printf ("errno = %d, ORC Error(by system function calling): %s\n",  */
      /*             error, strerror (error)); */
      perror("ORC Error(by system function calling) ");
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

void**
ORCdarraynew (int row, int col, int size)
{
   void **arr;

   arr = (void **) malloc (sizeof(void *) * row + size * row * col);
   if ( arr != NULL ) {
      void *head;

      head = (void *) arr + sizeof(void *) * row;
      memset (arr, 0, sizeof(void *) * row + size * row * col);
      while (row--) {
         arr[row] = head + size * row * col;
      }
   }

   return arr;
} /* End of ORCdarraynew*/

void
ORCdarrayfree (void **arr)
{
   if ( arr != NULL ) {
      free (arr);
   }
} /* End of ORCdarrayfree*/

