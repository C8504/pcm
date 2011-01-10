%module PCM_Python
%apply long long *OUTPUT { long long *result };
%{
#include "PCM.h"
#include "PCMerrormap.h"
#include "PCMstring.h"
#include "PCMfile.h"
#include "PCMmath.h"
#include "PCMarray.h"
#include "PCMfind.h"
#include "PCMsort.h"
#include "PCMlinkedlist.h"
#include "PCMconstant.h"
#include "PCMstack.h"
%}

int PCMpower (int base, int  n, long long *result);
