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
#include "PCMstring.h"

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

    // test PCMstrlen and PCMstrtrim
    char str1[] = "";
    char str2[] = " ";
    char str3[] = "a b ";
    char str4[] = "ab   ";

    CALL(PCMstrlen (str1, &len));
    printf ("str1 = %s, len = %d\n", str1,len);

    CALL(PCMstrlen (str2, &len));
    printf ("str2 = %s, len = %d\n", str2,len);

    CALL(PCMstrtrim (str1));
    CALL(PCMstrtrim (str2));
    CALL(PCMstrtrim (str3));
    CALL(PCMstrtrim (str4));
    CALL(PCMstrlen (str1, &len));
    printf ("str1 = %s, %d\n", str1, len);

    CALL(PCMstrlen (str2, &len));
    printf ("str2 = %s, %d\n", str2, len);

    CALL(PCMstrlen (str3, &len));
    printf ("str3 = %s, %d\n", str3, len);

    CALL(PCMstrlen (str4, &len));
    printf ("str4 = %s, %d\n", str4, len);

    // test PCMstreverse
    PCMstrncpy(str, "Thisisastring", sizeof(str));
    /*    strncpy(str, "Thisisastring", sizeof(str)); */
    printf ("str = %s\n", str);
    CALL(PCMstreverse (str));
    printf ("str = %s\n", str);

    CALL(PCMstreverse (str));
    printf ("str = %s\n", str);

    // test PCMstrdelcharofstring and PCMstrlen
    /*    strncat(str, "This is a string", 10); */
    /* strncpy(str, "This is a string", 10); */
    CALL(PCMstrlen (str, &len));
    printf ("str = %s, len = %d\n", str,len);
    CALL(PCMdelcharofstring(str, 'p'));
    printf ("%s",str);
    printf ("\n");

    CALL(PCMdelcharofstring(str, 't'));
    printf ("%s", str);
    printf ("\n");

    CALL(PCMstrlen (str, &len));
    printf ("str = %s, len = %d\n", str,len);


    // test PCMstrncat function
    char tail[] = "test_PCMstrncat";
    /*    CALL(PCMstrncat (str, tail, sizeof tail); */
    CALL(PCMstrncat (str, tail, -1));
    CALL(PCMstrlen (str, &len));
    printf ("str = %s, len = %d\n", str,len);

    // test PCMstrblkstoblk
    char bstr[] = "  test  PCMstrblkstoblk  !";
    /*    char bstr[] = "ab      "; */
    /*    char bstr[] = "        ab      "; */
    /*    char bstr[] = "        a    b      "; */
    CALL(PCMstrblkstoblk (bstr));
    CALL(PCMstrlen (bstr, &len));
    printf ("bstr = %s, len = %d\n", bstr,len);

    // test PCMstrindex
    char bigstr[] = "defefgdefk";
    char substr[] = "def";
    int index;
    CALL(PCMstrindex (bigstr, substr, &index));

    printf ("The last %s in %s at %d\n", substr, bigstr, index);

    //CALL(PCMdelcharofstring(NULL, 't'));
    //printf ("%s",str);
    //printf ("\n");

TERMINATE:
    PCMcheckerror (error);
    return 0;
}
