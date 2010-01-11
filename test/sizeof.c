#include <stdio.h>
#include <assert.h>

int main(void)
{
   unsigned **p;
   double **d;
   char ***c;

   assert(sizeof *c == sizeof **c
         && sizeof *p == sizeof **c
         && sizeof *d == sizeof **c); 

   return 0;
}
