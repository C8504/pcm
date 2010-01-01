#include "ORCfile.h"
static int ORCfilepgetinfo(ORCfile *fp);

int
ORCfilecreate (ORCfile **fp) {
   int error = 0;

   *fp = malloc(sizeof **fp);
   if ( *fp == NULL ) {
      error = ORCERRNOMEMORY;
      goto TERMINATE;
   }

   (*fp)->p       = NULL;
   error = ORCstrncpy((*fp)->name, "", sizeof (*fp)->name + 1);
   if ( error )  goto TERMINATE;
   (*fp)->nlines  = 0L;
   (*fp)->nchars  = 0L;
   (*fp)->ndigits = 0L;
   (*fp)->nwords  = 0L;

TERMINATE:
   return error;
} /* End of ORCfilecreate*/

int
ORCfilefree (ORCfile **fp){
   int error = 0;

   if ( fp == NULL ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

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

   if ( fp == NULL ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }
   else {
      if ((fp->p = fopen(name, "r")) == NULL) {
         error = errno;
         goto TERMINATE;
      }
      else {
         error = ORCstrncpy(fp->name, name, sizeof fp->name - 1);
         if ( error )  goto TERMINATE;

         error = ORCfilepgetinfo(fp);
         if ( error )  goto TERMINATE;
      }
   }
TERMINATE:
   return error;
} /* End of ORCfileopen */

   int
ORCfilestatistics (ORCfile *fp)
{
   int error = 0;

   if ( fp == NULL) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }
   printf ("File name: %s\n", fp->name);
   printf ("There are %ld lines\n", fp->nlines);
   printf ("There are %ld words\n", fp->nwords);
   printf ("There are %ld chars\n", fp->nchars);
   printf ("There are %ld digits\n", fp->ndigits);

TERMINATE:
   return error;
} /* End of ORCfilestatistics*/

static int
ORCfilepgetinfo (ORCfile *fp){
   int error = 0;
   int state = 0;
   int c;

   while ((c = getc(fp->p)) != EOF) {
      ++fp->nchars;

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

   rewind (fp->p);

TERMINATE:
   return error;
} /* ORCfilepgetinfo*/

   int
ORCfilegetline (ORCfile *fp,
      int     max,
      char    *line,
      int     *length)
{
   int error = 0;
   int c     = 0;
   int i     = 0;

   while ((i < max-1              ) &&
         ((c = getc(fp->p)) != EOF) &&
         (c != '\n'               )   ) {
      line[i] = c;
      ++i;
   }

   if ( c == '\n' ) {
      line[i] = '\n';
      ++i;
   }

   line[i] = '\0';
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
   char line[ORCMAXLINE] = {0};

   *max = len;
   do {
      error = ORCfilegetline (fp, ORCMAXLINE, line, &len);
      if ( error )  goto TERMINATE;
      if ( len > *max ) {
         *max = len;
         error = ORCstrncpy (maxline, line, ORCMAXLINE);
         if ( error )  goto TERMINATE;
      }
   }
   while ( len != 0 );

   rewind (fp->p);

TERMINATE:
   return error;
} /* End of ORCfilegetmaxline*/

