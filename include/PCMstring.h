#ifndef H_PCMSTRING
#define H_PCMSTRING

#ifdef __cplusplus
extern "C" {
#endif

#include "PCM.h"
   int PCMdelcharofstring (char * str,      int c);
   int PCMstrlen          (const char *str, size_t *len);
   int PCMstrtrim         (char *str);
   int PCMstreverse       (char *str);
   int PCMstrncpy         (char *des,        const char *src, int n);
   int PCMstrncat         (char *des,        const char *src, int n);
   /* Replace blanks with blank in string*/
   int PCMstrblkstoblk    (char *str);
   int PCMstrindex        (char *str,        char* substr,     int *index);

#ifdef __cplusplus
}
#endif

#endif
