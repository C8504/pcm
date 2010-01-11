#ifndef H_ORCSTRING
#define H_ORCSTRING

#ifdef __cplusplus
extern "C" {
#endif

#include "ORC.h"
   int ORCdelcharofstring(char * str, int c);
   int ORCstrlen(const char *str, size_t *len);
   int ORCstrtrim(char *str);
   int ORCstreverse(char *str);
   int ORCstrncpy(char *des, const char *src, int n);
   int ORCstrncat(char *des, const char *src, int n);
   /* Replace blanks with blank in string*/ 
   int ORCstrblankstoblank(char *str);

#ifdef __cplusplus
}
#endif

#endif
