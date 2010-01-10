#ifndef H_ORCFILE
#define H_ORCFILE

#ifdef __cplusplus
extern "C" {
#endif
#include "ORC.h"

   typedef struct {
      FILE *p;
      char name[ORCFILENAME];
      long long nlines;
      long long nwords;
      long long nchars;
      long long ndigits;
   } ORCfile;

   int ORCfilecreate(ORCfile **fp);
   int ORCfilefree(ORCfile **fp);

   int ORCfileopen(ORCfile *fp, const char *name);
   int ORCfilestatistics(ORCfile *fp);
   int ORCfilegetline(/*in*/ ORCfile *fp,
         /*in*/ int     max,
         /*out*/char    *line,
         /*out*/int     *length);
   int ORCfilegetmaxline(ORCfile *fp, char *maxline, int *max);
   int ORCfilegetinfo(ORCfile *fp);

#ifdef __cplusplus
}
#endif

#endif
