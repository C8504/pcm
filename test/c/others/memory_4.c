#include <stdio.h>

char* GetMemory(int num)
{
   char *p = (char*)malloc(num);
   return p;
}

int main(void)
{
   /* code */
   char *str = NULL;
   str = GetMemory(100);
   strcpy(str, "hello, world");
   printf("%s\n", str);
   return 0;
}
