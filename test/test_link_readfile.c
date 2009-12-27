#include "ORClinkedlist.h"

int main(void)
{
   int i;
   int error = 0;
   FILE *fp;
   char line[256];
   ORClinkedlist *mylist1 = NULL;
   ORClinkedlist *mylist2 = NULL;

   fp = fopen ("..\\README", "r");
   if ( fp == NULL)  {
      printf ("ORC Error: fopen error!\n");
      goto TERMINATE;
   }
   error = ORClinkedlistinit (&mylist1);
   if ( error )  goto TERMINATE;
   error = ORClinkedlistinit (&mylist2);
   if ( error )  goto TERMINATE;


   while (fgets (line, 256, fp) != NULL) {
      error = ORClinkedlistappend (mylist1, line);
      if ( error )  goto TERMINATE;
      if ( strstr (line, "malloc") != NULL) {
         error = ORClinkedlistappend (mylist2, line);
         if ( error )  goto TERMINATE;
      }
   }

   ORClinkedlistoutput (mylist1, NULL);
   ORClinkedlistoutput (mylist2, NULL);
   ORClinkedlistfree (&mylist1);
   ORClinkedlistfree (&mylist2);
   fclose (fp);

TERMINATE:
   ORCcheckerror (error); 
   return 0;
}
