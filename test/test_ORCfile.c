// using splint to check bounds
// splint test.c +bounds
#include "ORCfile.h"

   int
main(int argc, char **argv)
   /* main () */
{
   int error = 0;

   ORCfile *fp = NULL;

   error = ORCfilecreate(&fp);
   if ( error )  goto TERMINATE;

   /* error = ORCfileopen(fp, "c:\\orc\\data\\git.txt"); */
   /*    error = ORCfileopen(fp, "c:\\orc\\data\\01.mps"); */
   error = ORCfileopen(fp, argv[1]);
   if ( error )  goto TERMINATE;

  
   char str[1000] = {0};
   int len = 0;
   do{
      error = ORCfilegetline(fp, 1000, str, &len);
      if ( error )  goto TERMINATE;
      printf ("%s which length = %d\n", str, len);
   }
   while (len > 0);
   
   error = ORCfilestatistics(fp);
   if ( error )  goto TERMINATE;

   error = ORCfilefree(&fp);
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror(error);
   return 0;
}
