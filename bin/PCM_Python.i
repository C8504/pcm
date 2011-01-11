%module PCM_Python
%{
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
%include ""

int PCMpower (int, int, long long *OUTPUT);

PCMfile* PCMfilecreate();
int PCMfilefree  (PCMfile *fp);
int PCMfileopen      (PCMfile *fp, const char *name);
int PCMfilestat      (PCMfile *fp);
