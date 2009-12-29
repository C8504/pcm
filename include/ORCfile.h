#ifndef H_ORCFILE
#define H_ORCFILE
#include "ORC.h"

typedef struct {
   FILE *p;
   char name[20];
   long long nlines;
   long long nwords;
   long long nchars;
   long long ndigits;
} ORCfile;

int ORCfilecreate(ORCfile **fp);
int ORCfilefree(ORCfile **fp);

int ORCfileopen(ORCfile *fp, const char *name);
int ORCfilestatistics(ORCfile *fp);
/* int ORCfilegetline(ORCfile *fp, char *line); */
/* int ORCfilegetmaxline(ORCfile *fp); */

#endif
