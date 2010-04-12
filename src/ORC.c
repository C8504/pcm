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

int
ORCcompare (const void *x,
            const void *y) {
   const int *a = (const int*)x;
   const int *b = (const int*)y;

   if (*a > *b)
      return 1;
   else if (*a < *b)
      return -1;
   else
      return 0;
}

void**
ORCdarraynew (size_t row, size_t col, size_t size)
{
   void **arr;

   arr = malloc (sizeof(*arr) * row + size * row * col);

   if ( arr != NULL ) {
      void *head;

      head = (void *) arr + sizeof(*arr) * row;
      memset (arr, 0, sizeof(*arr) * row + size * row * col);

      while (row--) {
         arr[row] = head + size * row * col;
      }
   }

   return arr;
} /* End of ORCdarraynew*/

void
ORCdarrayfree (void **arr)
{
   free (arr);
} /* End of ORCdarrayfree*/

int 
ORCcheckpointer(void *p)
{
   int error = 0;
   
   if ( p == NULL ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

TERMINATE:
   return error;
}/* End of ORCcheckpointer*/

