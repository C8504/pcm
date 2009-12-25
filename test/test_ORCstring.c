/*
 *strncpy() 最初被设计为用来处理一种现在已经废弃的数据结构---定长, 
 不必 '\0' 结束的 ”字符串"。strncpy 的另一个怪癖是它会用多个 '\0'
 填充短串, 直到达到指定的长度。在其它环境中使用 strncpy() 有些麻烦, 
 因为你必须经常在目的串末尾手工加 '\0'。 

 你可以用 strncat 代替 strncpy 来绕开这个问题: 如果目的串开始时为空 
 (就是说, 如果你先用 *dest = '\0'), strncat() 就可以完成你希望 strncpy() 
 完成的事情。另外一个方法是用 sprintf(dest, "%.*s", n, source)。 
 如果需要复制任意字节 (而不是字符串), memcpy() 是个比 strncpy() 更好的选择。
 */

#include<stdio.h>
#include "ORCstring.h"

int main (void)
{
   int i = 0;
   int error = 0;
   char str[20] = {0};
/*    char str[] = {'T', 'h', 'i', 's', '\0'}; */
/*    char str[] = "Thip"; */
/*    char *str = "Thip"; */
/*    str[1] = 'o'; */
   //strncat(str, "This is a string", 10);
   //strncpy(str, "This is a string", 10);
   strcpy(str, "This is a string");
   error = ORCdelcharofstring(str, 'p');
   if ( error )  goto TERMINATE;
   printf (str);
   printf ("\n");

   error = ORCdelcharofstring(str, 't');
   if ( error )  goto TERMINATE;
   printf (str);
   printf ("\n");

   error = ORCdelcharofstring(NULL, 't');
   if ( error )  goto TERMINATE;
   printf (str);
   printf ("\n");

TERMINATE:
   if ( error ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

      for (i = 0; i < nErrors; ++i) {
         if ( errorMap[i].error == error ) {
            printf ("ORC Error: %s\n", errorMap[i].str);
         }
      }
   }

   return 0;
}
