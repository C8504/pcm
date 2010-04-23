#include "ORCfile.h"

int
ORCfilecreate (ORCfile **fp) {
   int i     = 0;
   int error = 0;

   *fp = malloc (sizeof **fp);
   if ( *fp == NULL ) {
      error = ORCERRNOMEMORY;
      goto TERMINATE;
   }

   (*fp)->p       = NULL;
   error = ORCstrncpy ((*fp)->name, "", sizeof (*fp)->name + 1);
   if ( error )  goto TERMINATE;
   (*fp)->nlines  = 0LL;
   (*fp)->nbytes  = 0LL;
   (*fp)->ndigits = 0LL;
   (*fp)->nwords  = 0LL;

   for (i = 0; i < ORCCHAR; ++i) {
      (*fp)->countofchar[i] = 0;
   }

TERMINATE:
   return error;
} /* End of ORCfilecreate*/

int
ORCfilefree (ORCfile **fp){
   int error = 0;

   error = ORCcheckpointer (fp);
   if ( error )  goto TERMINATE;

   if ( (*fp)->p != NULL ){
      fclose((*fp)->p);
      (*fp)->p = NULL;
   }

   free (*fp);
   *fp = NULL;

TERMINATE:
   return error;
} /* End of ORCfilefree*/

int
ORCfileopen (ORCfile *fp, const char *name){
   int error = 0;

   error = ORCcheckpointer (fp);
   if ( error )  goto TERMINATE;

   if ((fp->p = fopen(name, "r")) == NULL) {
      error = errno;
      goto TERMINATE;
   }
   else {
      error = ORCstrncpy(fp->name, name, sizeof fp->name - 1);
      if ( error )  goto TERMINATE;
    }

TERMINATE:
   return error;
} /* End of ORCfileopen */

   int
ORCfilestatistics (ORCfile *fp)
{
   int error = 0;
   int i     = 0;
   
   error = ORCcheckpointer (fp);
   if ( error )  goto TERMINATE;

   error = ORCfilegetinfo(fp);
   if ( error )  goto TERMINATE;

   printf ("File name: %s\n", fp->name);
   printf ("There are %lld lines\n", fp->nlines);
   printf ("There are %lld words\n", fp->nwords);
   printf ("There are %lld bytes\n", fp->nbytes);
   printf ("There are %lld digits\n", fp->ndigits);

/*   for (i = 0; i < ORCCHAR; ++i) {*/
/*      if (isprint(i)) {*/
/*         printf ("Count of char ");*/
/*         putchar((char)(i));*/
/*         putchar(':');*/
/*         printf ("%lld", fp->countofchar[i]);*/
/*         putchar('\n');*/
/*      }*/
/*   }*/

TERMINATE:
   return error;
} /* End of ORCfilestatistics*/

int
ORCfilegetinfo (ORCfile *fp){
   int error = 0;
   int state = 0;
   int c;

   error = ORCcheckpointer (fp);
   if ( error )  goto TERMINATE;

   while ((c = getc(fp->p)) != EOF) {
      ++fp->nbytes;
      ++fp->countofchar[c];

      if ( '\n' == c ) {
         ++fp->nlines;
      }

      if ( c >= '0' && c <= '9') {
         ++fp->ndigits;
      }

      if ( ( (c >= 91)  && (c <= 96)  )  ||
            ( (c >= 0)   && (c <= 64)  )  ||
            ( (c >= 123) && (c <= 127) ) )  {
         state = 0;
      }
      else if (0 == state) {
         state = 1;
         ++fp->nwords;
      }
   }

   // rewind to the head of file 
   rewind (fp->p);

TERMINATE:
   return error;
} /* End of ORCfilepgetinfo*/

   int
ORCfilegetline (ORCfile *fp,
      int     max,
      char    *line,
      int     *length)
{
   int error = 0;
   int c     = 0;
   int i     = 0;

   error = ORCcheckpointer (fp);
   if ( error )  goto TERMINATE;

   while ((i < max-1               ) &&
         ((c = getc(fp->p)) != EOF ) &&
         (c != '\n'                )   ) {
      line[i] = c;
      ++i;
   }

   if ( c == '\n' ) {
      line[i] = '\n';
   }

   line[i+1] = '\0';
   *length = i;

TERMINATE:
   return error;
} /* End of ORCfilegetline */

int
ORCfilegetmaxline (ORCfile *fp,
      char     *maxline,
      int      *max) {
   int error = 0;
   int len   = 0;
   char line[ORCFILEMAXLINE] = {0};
   
   error = ORCcheckpointer (fp);
   if ( error )  goto TERMINATE;

   *max = len;
   do {
      error = ORCfilegetline (fp, ORCFILEMAXLINE, line, &len);
      if ( error )  goto TERMINATE;
      if ( len > *max ) {
         *max = len;
         error = ORCstrncpy (maxline, line, ORCFILEMAXLINE);
         if ( error )  goto TERMINATE;
      }
   }
   while ( len != 0 );

   rewind (fp->p);

TERMINATE:
   return error;
} /* End of ORCfilegetmaxline*/

