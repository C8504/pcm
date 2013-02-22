#include <stdio.h>

char* GetMemory(void)
{
   char p[] = "hello,world";
   return p;
}

int main(void)
{
   /* code */
   char *str = NULL;
   str = GetMemory();
   printf("%s\n", str);
   return 0;
}
