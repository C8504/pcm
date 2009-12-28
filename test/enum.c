#include <stdio.h>

enum computer {keyboard, CPU, screen, printer, mouse};

int main(void)
{
   enum computer comp;

   comp = CPU;

   printf("%d", comp);

   return 0;
}
