#include "linkedlist.h"

int main(void)
{
   int i = 0;
   int error = 0;

   ORClinkedlist *mylist = NULL;

   error = ORClinkedlistinit (&mylist);
   if ( error )  goto TERMINATE;

   error = ORClinkedlistoutput (mylist, ":");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistfree (&mylist);
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
