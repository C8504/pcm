#include "PCMlinkedlist.h"
int testmanyelements()
{
   int i;
   int error = 0;
   enum PCMPOPTYPE type;
   PCMlinkedlist* mylist = NULL;

   CALL(PCMlinkedlistinit (&mylist));

   // insert  elements here
   CALL(PCMlinkedlistinsert (mylist, 0, "1"));
   CALL(PCMlinkedlistinsert (mylist, 1, "2"));
   CALL(PCMlinkedlistinsert (mylist, PCMlinkedlistlength(mylist), "end"));
   CALL(PCMlinkedlistoutput (mylist, ":"));

   // append 10 elements
   for (i = 0; i < 10; ++i) {
      CALL(PCMlinkedlistappend (mylist, "a"));
   }

   CALL(PCMlinkedlistoutput (mylist, ":"));

   // append 10 elements too
   for (i = 0; i < 10; ++i) {
      CALL(PCMlinkedlistappend (mylist, "b"));
   }
   CALL(PCMlinkedlistoutput (mylist, ":"));

   // insert  elements here
   CALL(PCMlinkedlistinsert (mylist, 1, "3"));
   CALL(PCMlinkedlistinsert (mylist, 2, "4"));
   CALL(PCMlinkedlistinsert (mylist, PCMlinkedlistlength(mylist), "end"));
   CALL(PCMlinkedlistoutput (mylist, ":"));

   // pop like stack
   type = PCMPOPSTACK;
   for (i = 0; i < 5; ++i) {
      CALL(PCMlinkedlistpop (mylist, type));
   }
   CALL(PCMlinkedlistoutput (mylist, ":"));

   // pop like queue
   type = PCMPOPQUEUE;
   for (i = 0; i < 5; ++i) {
      CALL(PCMlinkedlistpop (mylist, type));

   }
   CALL(PCMlinkedlistoutput (mylist, ":"));

   // pop like stack
   type = PCMPOPQUEUE;
   for (i = 0; i < 10; ++i) {
      CALL(PCMlinkedlistpop (mylist, type));
   }
   CALL(PCMlinkedlistoutput (mylist, ":"));

   // insert 10 elements again
   for (i = 0; i < 10; ++i) {
      CALL(PCMlinkedlistappend (mylist, "a"));
   }

   CALL(PCMlinkedlistoutput (mylist, ":"));
   CALL(PCMlinkedlistfree (&mylist));

   if ( NULL == mylist )  printf ("free list successfully!\n\n");

TERMINATE:

   if ( mylist )  PCMlinkedlistfree (&mylist);
   return error;
}

int main(void)
{
   int i;
   int error = 0;

   CALL(testmanyelements());

TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
