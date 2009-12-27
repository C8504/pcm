#include "ORCseqlist.h"

int main(void)
{
   int i;
   int error = 0;

   int a[5] = {1, 3, 3, 7, 7};
   int b[5] = {1, 3, 6, 6, 10};

   ORCSList odd = NULL;
   ORCSList even = NULL;

   error = ORCseqlistinit (&odd);
   if ( error )  goto TERMINATE;

   error = ORCseqlistinit (&even);
   if ( error )  goto TERMINATE;

   error = ORCseqlistcopy (odd, a, 5);
   if ( error )  goto TERMINATE;

   error = ORCseqlistcopy (even, b, 5);
   if ( error )  goto TERMINATE;

   error = ORCseqlistmerge (odd, even);
   if ( error )  goto TERMINATE;

   error = ORCseqlistdeleteR (odd);
   if ( error )  goto TERMINATE;

   error = ORCseqlistoutput (odd);
   if ( error )  goto TERMINATE;

   error = ORCseqlistoutput (even);
   if ( error )  goto TERMINATE;

   error = ORCseqlistfree (&odd);
   if ( error )  goto TERMINATE;

   error = ORCseqlistfree (&even);
   if ( error )  goto TERMINATE;

   if ( even == NULL )  printf ("free even successfully!\n");
   if ( odd == NULL  )  printf ("free odd successfully!\n");
TERMINATE:
   ORCcheckerror (error);
   if ( NULL != odd  )  ORCseqlistfree (&odd);
   if ( NULL != even )  ORCseqlistfree (&even);

   return 0;
}
