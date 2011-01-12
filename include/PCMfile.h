#ifndef H_PCMFILE
#define H_PCMFILE

#ifdef __cplusplus
extern "C" {
#endif
#include "PCM.h"
   typedef struct {
      FILE *p;
      char name[PCMFILENAME];
      long long nlines;
      long long nwords;
      long long nbytes;
      long long ndigits;
      long long countofchar[PCMCHAR];
   } PCMfile;

   PCMfile* PCMfilecreate();
   void PCMfilefree  (PCMfile *fp);

   int PCMfileopen      (PCMfile *fp, const char *name);
   int PCMfilestat      (PCMfile *fp);
   int PCMfilegetline   (/*in*/ PCMfile *fp,
                         /*in*/ int     max,
                         /*out*/char    *line,
                         /*out*/int     *length);
   int PCMfilegetmaxline(PCMfile *fp, char *maxline, int *max);

#ifdef __cplusplus
}
#endif

#endif
