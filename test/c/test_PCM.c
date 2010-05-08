#include "PCM.h" 

int main(void)
{
   int **p;
   int i = 0;
   int j = 0;
   size_t nrows = 10;
   size_t ncols = 10;

   p = (int **)PCMdarraynew(nrows, ncols, sizeof(int));
  
   for (i = 0; i < nrows; ++i) {
      for (j = 0; j < ncols; ++j){
         p[i][j] = ncols*i + j;
      }
   }
 

   for (i = 0; i < nrows; ++i) {
      for (j = 0; j < ncols; ++j){
         printf ("p[%d][%d] = %d\n", i, j, p[i][j]);
      }
   }

   PCMdarrayfree (p);
   
   return 0;
}
