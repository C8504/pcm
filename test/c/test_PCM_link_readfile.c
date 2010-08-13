#include "PCMlinkedlist.h"

int main(void)
{
   int i;
   int error = 0;
   FILE *fp;
   char line[256];
   PCMlinkedlist *mylist1 = NULL;
   PCMlinkedlist *mylist2 = NULL;

   fp = fopen ("../data/PCM.c", "r");
   if ( fp == NULL)  {
      printf ("PCM Error: fopen error!\n");
      goto TERMINATE;
   }
   CALL(PCMlinkedlistinit (&mylist1));
   CALL(PCMlinkedlistinit (&mylist2));


   while (fgets (line, 256, fp) != NULL) {
      CALL(PCMlinkedlistappend (mylist1, line));
      if ( strstr (line, "malloc") != NULL) {
         CALL(PCMlinkedlistappend (mylist2, line));
      }
   }

   PCMlinkedlistoutput (mylist1, NULL);
   PCMlinkedlistoutput (mylist2, NULL);
   PCMlinkedlistfree (&mylist1);
   PCMlinkedlistfree (&mylist2);
   fclose (fp);

TERMINATE:
   PCMcheckerror (error); 
   return 0;
}
