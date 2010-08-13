#include "PCMseqlist.h"

int main(void)
{
   int i;
   int error = 0;

   int a[5] = {1, 3, 3, 7, 7};
   int b[5] = {1, 3, 6, 6, 10};

   PCMSList odd = NULL;
   PCMSList even = NULL;

   CALL(PCMseqlistinit (&odd));
   CALL(PCMseqlistinit (&even));
   CALL(PCMseqlistcopy (odd, a, 5));
   CALL(PCMseqlistcopy (even, b, 5));
   CALL(PCMseqlistmerge (odd, even));
   CALL(PCMseqlistdeleteR (odd));
   CALL(PCMseqlistoutput (odd));
   CALL(PCMseqlistoutput (even));
   CALL(PCMseqlistfree (&odd));
   CALL(PCMseqlistfree (&even));

   if ( even == NULL )  printf ("free even successfully!\n");
   if ( odd == NULL  )  printf ("free odd successfully!\n");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != odd  )  PCMseqlistfree (&odd);
   if ( NULL != even )  PCMseqlistfree (&even);

   return 0;
}
