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
   CALL(PCMlinkedlistinit (&p));
   CALL(PCMlinkedlistoutput (p, ":"));
   CALL(PCMlinkedlistfree (&p));

TERMINATE:
   PCMcheckerror (error);
   return 0;
}
