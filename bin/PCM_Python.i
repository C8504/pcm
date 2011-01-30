%module PCM_Python
%{
#include "PCM.h"
#include "PCMfile.h"
#include "PCMarray.h"
#include "PCMstring.h"
#include "PCMfind.h"
#include "PCMsort.h"
#include "PCMmath.h"
#include "PCMconstant.h"
#include "PCMlinkedlist.h"
#include "PCMstack.h"
#include "PCMerrormap.h"
%}
%include "typemaps.i"
%include "carrays.i"
%include "cstring.i"
%cstring_bounded_output(char *line, 1024);
%array_class(int, intArray);

void PCMversion (char* line);
int PCMpower (int, int, long long *OUTPUT);
PCMfile* PCMfilecreate();


void PCMfilefree      (PCMfile *fp);
int PCMfileopen       (PCMfile *fp, const char *name);
int PCMfilestat       (PCMfile *fp);
int PCMfilegetmaxline (PCMfile *fp, char *line, int *OUTPUT);
int PCMfilegetline    (/*in*/ PCMfile *fp,
                       /*in*/ int     max,
                       /*out*/char    *line,
                       /*out*/int     *OUTPUT);
enum PCMSORTALG {PCMALGSORTSELECT = 80001,
                 PCMALGSORTBUBBLE,
                 PCMALGSORTQUICK,
                 PCMALGSORTSHELL,
                 PCMALGSORTINSERT};
enum PCMSEARCHALG {PCMALGORIGINFIND = 90001,
                   PCMALGBINFIND};
PCMarray* PCMarraynew    (const char* name);
int PCMarrayfree    (PCMarray *list);
int PCMarraylen     (PCMarray *list);
int PCMarrayoutput  (PCMarray *list);
int PCMarrayinsert  (PCMarray *list, int index, const int elem);
int PCMarraydelete  (PCMarray *list, int index, int* OUTPUT);
int PCMarraydeleteR (PCMarray *list);
int PCMarrayclear   (PCMarray *list);
int PCMarraymerge   (PCMarray *des,  const PCMarray* src);
int PCMarraycopy    (PCMarray *list, const int* arr, int count);
int PCMarraysort    (PCMarray *list, int length, enum PCMSORTALG alg);
int PCMarrayfind    (PCMarray *list, int length, const int elem,
                     int *OUTPUT, enum PCMSEARCHALG alg);
