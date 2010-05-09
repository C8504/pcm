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
   error = PCMlinkedlistinit (&mylist1);
   if ( error )  goto TERMINATE;
   error = PCMlinkedlistinit (&mylist2);
   if ( error )  goto TERMINATE;


   while (fgets (line, 256, fp) != NULL) {
      error = PCMlinkedlistappend (mylist1, line);
      if ( error )  goto TERMINATE;
      if ( strstr (line, "malloc") != NULL) {
         error = PCMlinkedlistappend (mylist2, line);
         if ( error )  goto TERMINATE;
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
