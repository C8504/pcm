#include "inout.h"

   int
main (void)
{
   int i = 0;
   int error = 0;

   error = inout();

   if ( error )  goto TERMINATE;

TERMINATE:

   if ( error ) {
      int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

         for (i = 0; i < nErrors; ++i) {
            if ( errorMap[i].error == error ) {
               printf ("ORC Error: %s\n", errorMap[i].str);
            }
         }
   }
   return 0;
}

