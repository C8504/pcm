#include "ORClinkedlist.h"

int main(void)
{
   int i = 0;
   int error = 0;

/*    ORClinkedlist *mylist = NULL; */
/*    ORClinkedlist mylist; */
/*    mylist = &l; */
/*    ORClinkedlist *p = &mylist; */
   ORClinkedlist *p = NULL;
   error = ORClinkedlistinit (&p);
   if ( error )  goto TERMINATE;

   error = ORClinkedlistoutput (p, ":");
   if ( error )  goto TERMINATE;

   error = ORClinkedlistfree (&p);
   if ( error )  goto TERMINATE;

TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
