// using splint to check bounds
// splint test.c +bounds
#include "ORCfile.h"

int
/* main(int argc, char **argv) */
main ()
{
   int error = 0;

   ORCfile *fp = NULL;

   error = ORCfilecreate(&fp);
   if ( error )  goto TERMINATE;

   error = ORCfileopen(fp, "c:\\orc\\data\\git.txt");
   /*    error = ORCfileopen(fp, "c:\\orc\\data\\01.mps"); */
   /*    error = ORCfileopen(fp, argv[1]); */
   if ( error )  goto TERMINATE;

   error = ORCfilestatistics(fp);
   if ( error )  goto TERMINATE;

   error = ORCfilefree(&fp);
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror(error);
   return 0;
}
