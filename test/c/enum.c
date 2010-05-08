#include <stdio.h>

enum computer {keyboard, CPU, screen, printer, mouse};
/*enum pi {"3.1415926" = 1};*/
/*enum number {1, 2 ,3};*/

int main(void)
{
   enum computer comp;

   comp = CPU;

   printf("%d", comp);

   return 0;
}
