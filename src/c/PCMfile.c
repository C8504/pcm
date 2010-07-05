#include "PCMfile.h"

int
PCMfilecreate (PCMfile **fp) {
   int i     = 0;
   int error = 0;

   *fp = malloc (sizeof **fp);
   if ( *fp == NULL ) {
      THROW(PCMERRNOMEMORY);
   }

   (*fp)->p       = NULL;
   error = PCMstrncpy ((*fp)->name, "", sizeof (*fp)->name + 1);
   if ( error )  goto TERMINATE;
   (*fp)->nlines  = 0LL;
   (*fp)->nbytes  = 0LL;
   (*fp)->ndigits = 0LL;
   (*fp)->nwords  = 0LL;

   for (i = 0; i < PCMCHAR; ++i) {
      (*fp)->countofchar[i] = 0;
   }

TERMINATE:
   return error;
} /* End of PCMfilecreate*/

int
PCMfilefree (PCMfile **fp){
   int error = 0;

   error = PCMcheckpointer (fp);
   if ( error )  THROW(error);

   if ( (*fp)->p != NULL ){
      fclose((*fp)->p);
      (*fp)->p = NULL;

   }

   free (*fp);
   *fp = NULL;

TERMINATE:
   return error;
} /* End of PCMfilefree*/

int
PCMfileopen (PCMfile *fp, const char *name){
   int error = 0;

   error = PCMcheckpointer (fp);
   if ( error )  THROW(error);

   if ((fp->p = fopen(name, "r")) == NULL) {
      THROW(errno);
   }
   else {
      error = PCMstrncpy(fp->name, name, sizeof fp->name - 1);
      if ( error ) {
         THROW(error);
      }
    }

TERMINATE:
   return error;
} /* End of PCMfileopen */

   int
PCMfilestatistics (PCMfile *fp)
{
   int error = 0;
   int i     = 0;
   
   error = PCMcheckpointer (fp);
   if ( error ) {
      THROW(error);
   }

   error = PCMfilegetinfo(fp);
   if ( error ) {
      THROW(error);
   }

   printf ("\n++++++++++++++++PCM file statistics++++++++++++++++++++\n");
   
   printf ("File name: %s\n", fp->name);
   printf ("There are %lld lines\n", fp->nlines);
   printf ("There are %lld words\n", fp->nwords);
   printf ("There are %lld bytes\n", fp->nbytes);
   printf ("There are %lld digits\n", fp->ndigits);

   printf ("\n++++++++++++++++END++++++++++++++++++++++++++++++++++++\n");
/*   for (i = 0; i < PCMCHAR; ++i) {*/
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
} /* End of PCMfilestatistics*/

int
PCMfilegetinfo (PCMfile *fp){
   int error = 0;
   int state = 0;
   int c;

   error = PCMcheckpointer (fp);
   if ( error ){
      THROW(error);
   }

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
} /* End of PCMfilepgetinfo*/

int
PCMfilegetline (PCMfile *fp,
      int     max,
      char    *line,
      int     *length)
{
   int error = 0;
   int c     = 0;
   int i     = 0;

   error = PCMcheckpointer (fp);
   if ( error ) {
      THROW(error);
   }

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
} /* End of PCMfilegetline */

int
PCMfilegetmaxline (PCMfile *fp,
      char     *maxline,
      int      *max) {
   int error = 0;
   int len   = 0;
   char line[PCMFILEMAXLINE] = {0};
   
   error = PCMcheckpointer (fp);
   if ( error ) {
      THROW(error);
   }

   *max = len;
   do {
      error = PCMfilegetline (fp, PCMFILEMAXLINE, line, &len);
      if ( error ) {
         THROW(error);
      }
      if ( len > *max ) {
         *max = len;
         error = PCMstrncpy (maxline, line, PCMFILEMAXLINE);
         if ( error )  {
            THROW(error);
         }
      }
   }
   while ( len != 0 );

   rewind (fp->p);

TERMINATE:
   return error;
} /* End of PCMfilegetmaxline*/

