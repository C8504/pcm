#ifndef H_ORCSTRING
#define H_ORCSTRING
#include "ORC.h"
int ORCdelcharofstring(char * str, int c);
int ORCstrlen(const char *str, size_t *len);
int ORCstrtrim(char *str);
int ORCstreverse(char *str);
int ORCstrncpy(char *des, const char *src, int n);
#endif
