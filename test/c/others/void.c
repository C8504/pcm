#include <stdio.h>

int main(void)
{
   /*    void n; */
   /*    void *n; */
   /*    *n = 1; */
   /*    n = 1; */

   /*    printf ("*n = %d\n", *n); */
   void *p;
   p = (void*)1;
   printf ("void *p = %p\n", p);
   printf ("(void*)1 = %d\n", (void*)1);
   printf ("(void*)hello = %s", (void*)"hello");
   return 0;
}
