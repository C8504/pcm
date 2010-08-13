#include "PCMarray.h"

int main(void)
{
   int i;
   int error = 0;

   int a[5] = {1, 3, 3, 7, 7};
   int b[5] = {1, 3, 6, 6, 10};

   PCMSList odd = NULL;
   PCMSList even = NULL;

   CALL(PCMarrayinit (&odd));
   CALL(PCMarrayinit (&even));
   CALL(PCMarraycopy (odd, a, 5));
   CALL(PCMarraycopy (even, b, 5));
   CALL(PCMarraymerge (odd, even));
   CALL(PCMarraydeleteR (odd));
   CALL(PCMarrayoutput (odd));
   CALL(PCMarrayoutput (even));
   CALL(PCMarrayfree (&odd));
   CALL(PCMarrayfree (&even));

   if ( even == NULL )  printf ("free even successfully!\n");
   if ( odd == NULL  )  printf ("free odd successfully!\n");
TERMINATE:
   PCMcheckerror (error);
   if ( NULL != odd  )  PCMarrayfree (&odd);
   if ( NULL != even )  PCMarrayfree (&even);

   return 0;
}
