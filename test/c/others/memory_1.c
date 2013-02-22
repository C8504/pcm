#include <stdio.h>

void GetMemory(char* p)
{
   p = (char*)malloc(100);
}

int main(void)
{
   /* code */
   char *str = NULL;
   GetMemory(str);
   strcpy(str, "hello, world");
   printf("%s\n", str);
   return 0;
}
