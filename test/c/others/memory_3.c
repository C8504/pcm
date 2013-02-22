#include <stdio.h>

void GetMemory(char **p, int num)
{
   *p = (char*)malloc(num);
}

int main(void)
{
   /* code */
   char *str = NULL;
   GetMemory(&str, 100);
   strcpy(str, "hello, world");
   printf("%s\n", str);
   free(str);
   return 0;
}
