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

   /* error = ORCfileopen(fp, "../data/git.txt"); */
   error = ORCfileopen(fp,"../data/01.mps");
   /*    error = ORCfileopen(fp, "makefile"); */
   /*    error = ORCfileopen(fp, "../data/questions.txt"); */
   /*    error = ORCfileopen(fp, argv[1]); */
   if ( error )  goto TERMINATE;

   char str[ORCFILEMAXLINE] = {0};
   int len = 0;

   error = ORCfilegetmaxline (fp, str, &len);
   if ( error )  goto TERMINATE;
   printf ("The longest line is: %s, length = %d\n", str, len);

   printf ("cat %s\n", fp->name);

   /*    do{ */
   /*       error = ORCfilegetline(fp, ORCFILEMAXLINE, str, &len); */
   /*       if ( error )  goto TERMINATE; */
   /*       printf ("%s", str); */
   /*    } */
   /*    while (len > 0); */

   error = ORCfilestatistics(fp);
   if ( error )  goto TERMINATE;

   error = ORCfilefree(&fp);
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror(error);
   return 0;
}
