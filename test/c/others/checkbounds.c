// using splint to check bounds
// splint test.c +bounds
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
   //char a[4];

   char *a = NULL;

   a = malloc (6 * sizeof(*a));
   //a = malloc (6);
   if ( a == NULL ){
      printf ("No memory\n");
      return 0;
   }

   a[0] = 'a';
   a[1] = 'b';
   a[2] = 'c';
   a[3] = 'd';
   a[4] = 'd';
   a[5] = 'd';
   a[6] = 'd';
   a[7] = 'd';
   printf ("%s\n", a);
   free (a);
   return 0;
}
