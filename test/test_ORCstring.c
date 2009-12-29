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
   size_t len = 0;
   int error = 0;
   char str[5] = {0};
   /*    char str[] = {'T', 'h', 'i', 's', '\0'}; */
   /*    char str[] = "Thip"; */
   /*    char *str = "Thip"; */
   /*    str[1] = 'o'; */

   // test ORCstrlen and ORCstrtrim
   char str1[] = "";
   char str2[] = " ";
   char str3[] = "a b ";
   char str4[] = "ab   ";

   error = ORCstrlen (str1, &len);
   if ( error )  goto TERMINATE;
   printf ("str1 = %s, len = %d\n", str1,len);

   error = ORCstrlen (str2, &len);
   if ( error )  goto TERMINATE;
   printf ("str2 = %s, len = %d\n", str2,len);

   error = ORCstrtrim (str1);
   if ( error )  goto TERMINATE;

   error = ORCstrtrim (str2);
   if ( error )  goto TERMINATE;

   error = ORCstrtrim (str3);
   if ( error )  goto TERMINATE;

   error = ORCstrtrim (str4);
   if ( error )  goto TERMINATE;

   error = ORCstrlen (str1, &len);
   if ( error )  goto TERMINATE;
   printf ("str1 = %s, %d\n", str1, len);

   error = ORCstrlen (str2, &len);
   if ( error )  goto TERMINATE;
   printf ("str2 = %s, %d\n", str2, len);

   error = ORCstrlen (str3, &len);
   if ( error )  goto TERMINATE;
   printf ("str3 = %s, %d\n", str3, len);

   error = ORCstrlen (str4, &len);
   if ( error )  goto TERMINATE;
   printf ("str4 = %s, %d\n", str4, len);

   // test ORCstreverse
   ORCstrncpy(str, "Thisisastring", sizeof(str));
   /*    strncpy(str, "Thisisastring", sizeof(str)); */
   printf ("str = %s\n", str);
   error = ORCstreverse (str);
   if ( error )  goto TERMINATE;
   printf ("str = %s\n", str);

   error = ORCstreverse (str);
   if ( error )  goto TERMINATE;
   printf ("str = %s\n", str);

   // test ORCstrdelcharofstring and ORCstrlen
   /*    strncat(str, "This is a string", 10); */
   /* strncpy(str, "This is a string", 10); */
   error = ORCstrlen (str, &len);
   if ( error )  goto TERMINATE;
   printf ("str = %s, len = %d\n", str,len);
   if ( error )  goto TERMINATE;
   error = ORCdelcharofstring(str, 'p');
   if ( error )  goto TERMINATE;
   printf (str);
   printf ("\n");

   error = ORCdelcharofstring(str, 't');
   if ( error )  goto TERMINATE;
   printf (str);
   printf ("\n");

   error = ORCstrlen (str, &len);
   if ( error )  goto TERMINATE;
   printf ("str = %s, len = %d\n", str,len);

   error = ORCdelcharofstring(NULL, 't');
   if ( error )  goto TERMINATE;
   printf (str);
   printf ("\n");

TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
