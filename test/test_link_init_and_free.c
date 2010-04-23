#include "PCMlinkedlist.h"

int main(void)
{
   int i = 0;
   int error = 0;

/*    PCMlinkedlist *mylist = NULL; */
/*    PCMlinkedlist mylist; */
/*    mylist = &l; */
/*    PCMlinkedlist *p = &mylist; */
   PCMlinkedlist *p = NULL;
   error = PCMlinkedlistinit (&p);
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistoutput (p, ":");
   if ( error )  goto TERMINATE;

   error = PCMlinkedlistfree (&p);
   if ( error )  goto TERMINATE;

TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
