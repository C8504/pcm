#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;

   int a[5] = {1, 3, 3, 7, 7};
   int b[5] = {1, 3, 6, 6, 10};

   PCMSList odd = NULL;
   PCMSList even = NULL;

   error = PCMseqlistinit (&odd);
   if ( error )  goto TERMINATE;

   error = PCMseqlistinit (&even);
   if ( error )  goto TERMINATE;

   error = PCMseqlistcopy (odd, a, 5);
   if ( error )  goto TERMINATE;

   error = PCMseqlistcopy (even, b, 5);
   if ( error )  goto TERMINATE;

   error = PCMseqlistmerge (odd, even);
   if ( error )  goto TERMINATE;

   error = PCMseqlistdeleteR (odd);
   if ( error )  goto TERMINATE;

   error = PCMseqlistoutput (odd);
   if ( error )  goto TERMINATE;

   error = PCMseqlistoutput (even);
   if ( error )  goto TERMINATE;

   error = PCMseqlistfree (&odd);
   if ( error )  goto TERMINATE;

   error = PCMseqlistfree (&even);
   if ( error )  goto TERMINATE;

   if ( even == NULL )  printf ("free even successfully!\n");
   if ( odd == NULL  )  printf ("free odd successfully!\n");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != odd  )  PCMseqlistfree (&odd);
   if ( NULL != even )  PCMseqlistfree (&even);

   return 0;
}
