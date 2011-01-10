%module PCM_Python
%apply long long *OUTPUT { long long *result };

int PCMpower (int base, int  n, long long *result);
int PCMfilestat (const char* filename);
