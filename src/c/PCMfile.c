#include "PCMfile.h"

PCMfile* 
PCMfilecreate () {
   int error = 0;
   int i     = 0;
   PCMfile *fp = NULL;

   PCM_ALLOC(fp, 1, *fp);

   fp->p       = NULL;
   PCMstrncpy (fp->name, "", sizeof fp->name + 1);
   fp->nlines  = 0LL;
   fp->nbytes  = 0LL;
   fp->ndigits = 0LL;
   fp->nwords  = 0LL;

   for (i = 0; i < PCMCHAR; ++i) {
      fp->countofchar[i] = 0;
   }

TERMINATE:
   return fp;
} /* End of PCMfilecreate*/

int
PCMfilefree (PCMfile *fp){
   DERROR;

   assert(fp != NULL);

   if ( fp->p != NULL ){
      fclose(fp->p);
      fp->p = NULL;

   }

   PCM_FREE(fp);
   
   RETURN;
} /* End of PCMfilefree*/

int
PCMfileopen (PCMfile *fp, const char *name){
   DERROR;

   assert(fp != NULL);

   if ((fp->p = fopen(name, "r")) == NULL) {
      THROW(errno);
   }
   else {
      THROW(PCMstrncpy(fp->name, name, sizeof fp->name - 1));
    }

   RETURN;
} /* End of PCMfileopen */

   int
PCMfilestat (PCMfile *fp)
{
   DERROR;
   int i     = 0;
   
   assert(fp != NULL);

   THROW(PCMfilegetinfo(fp));

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
   RETURN;
} /* End of PCMfilestatistics*/

int
PCMfilegetinfo (PCMfile *fp){
   DERROR;
   int state = 0;
   int c;

   assert(fp != NULL);

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
   
   RETURN;
} /* End of PCMfilepgetinfo*/

int
PCMfilegetline (PCMfile *fp,
      int     max,
      char    *line,
      int     *length)
{
   DERROR;
   int c     = 0;
   int i     = 0;

   assert(fp != NULL);

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

   RETURN;
} /* End of PCMfilegetline */

int
PCMfilegetmaxline (PCMfile *fp,
      char     *maxline,
      int      *max) {
   DERROR;
   int len   = 0;
   char line[PCMFILEMAXLINE] = {0};
   
   assert(fp != NULL);

   *max = len;
   do {
      THROW(PCMfilegetline (fp, PCMFILEMAXLINE, line, &len));
      if ( len > *max ) {
         *max = len;
         THROW(PCMstrncpy (maxline, line, PCMFILEMAXLINE));
      }
   }
   while ( len != 0 );

   rewind (fp->p);

   RETURN;
} /* End of PCMfilegetmaxline*/

