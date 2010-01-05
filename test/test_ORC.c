#include "ORC.h" 

int main(void)
{
   int **p;
   int i = 0;
   int j = 0;
   int nrows = 10;
   int ncols = 10;

   p = (int **)ORCdarraynew(nrows, ncols, sizeof(int));
  
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

   ORCdarrayfree (p);
   
   return 0;
}
