// using splint to check bounds
// splint test.c +bounds
#include "PCMfile.h"

   int
main(int argc, char **argv)
{
   int error = 0;

   if ( NULL == argv[1] ) {
      goto TERMINATE;
   }

   PCMfile *fp = PCMfilecreate();

   CALL(PCMfileopen(fp, argv[1]));
   CALL(PCMfilestat(fp));

   char str[PCMFILEMAXLINE] = {0};
   int len = 0;

   CALL(PCMfilegetmaxline (fp, str, &len));
   printf ("+The longest line is: %s, length = %d\n", str, len);

   /* printf ("cat %s\n", fp->name);*/

   /*do{*/
   /*error = PCMfilegetline(fp, PCMFILEMAXLINE, str, &len);*/
   /*if ( error )  goto TERMINATE;*/
   /*printf ("%s", str);*/
   /*}*/
   /*while (len > 0);*/


   PCMfilefree(fp);

TERMINATE:
   PCMcheckerror(error);
   return 0;
}
