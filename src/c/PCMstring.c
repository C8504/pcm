#include "PCMstring.h"
   int
PCMdelcharofstring (char * str,
      int  c)
{
   int i     = 0;
   int j     = 0;
   int error = 0;

   assert(str != NULL);
   for (i = 0, j = 0; str[i] != '\0'; ++i) {
      if ( str[i] != c ) {
         str[j++] = str[i];
      }
   }
   str[j] = '\0';

TERMINATE:
   return error;
} /* End of PCMdelcharofstring */

   int
PCMstrlen (const char *str,
      size_t     *len)
{
   int i     = 0;
   int error = 0;

   assert(str != NULL);
   while ( str[i] != '\0')
      ++i;
   *len = i;

TERMINATE:
   return error;
} /* End of PCMstrlen */

   int
PCMstrtrim (char *str)
{
   int error = 0;
   size_t n  = 0;
   int i     = 0;

   error = PCMstrlen (str, &n);
   if ( error ) {
      THROW(error);
   }
   if ( n > 0 ) {
      for (i = n-1; (i >= 0) && (str[i] == ' ' || str[i] == '\t'); --i);
      if ( i >= -1 ) {
         ++i;
         str[i] = '\0';
      }
   }

TERMINATE:
   return error;
} /* End of PCMstrtrim*/

   int
PCMstreverse (char *str)
{
   int error = 0;
   int i     = 0;
   int j     = 0;
   int temp  = 0;

   size_t n  = 0;

   error = PCMstrlen (str, &n);
   if ( error ) {
      THROW(error);
   }

   if ( n > 0 ) {
      j = n - 1;
      /* Can not use PCMswapint here */
      while (i < j) {
         PCMswapchar (str, i, j);
         ++i;
         --j;
      }
   }

TERMINATE:
   return error;
} /* End of ORcstreverse */

/*
   PCMstrncpy copy src to des, with length n.
   */
   int
PCMstrncpy (char       *des,
      const char *src,
      int n)
{
   int error  = 0;
   int i      = 0;
   size_t len = 0;


   assert(des != NULL);
   assert(src != NULL);
   error = PCMstrlen (src, &len);
   if ( error ) {
      THROW(error);
   }

   if ( len <= n ) {
      while ((*des++ = *src++) != '\0'){}
   }
   else {
      while (i < n) {
         des[i] = src[i];
         ++i;
      }
      des[i] = '\0';
   }

TERMINATE:
   return error;
} /* End of PCMstrncpy*/

   int
PCMstrncat (char *des,
      const char *src,
      int n)
{
   int error  = 0;
   int i      = 0;
   size_t len = 0;

   assert(des != NULL);
   assert(src != NULL);
   error = PCMstrlen (src, &len);
   if ( error ) {
      THROW(error);
   }

   while (*des != '\0') {
      ++des;
   }

   if( len <= n ) {
      while ((*des++ = *src++) != '\0');
   }
   else {
      while (i < n) {
         des[i] = src[i];
         ++i;
      }
      des[i] = '\0';
   }

TERMINATE:
   return error;
} /* End of PCMstrncat function*/

int
PCMstrblkstoblk (char *str) {
   int error = 0;
   int lastc = 'a';
   int i = 0;
   int j = 0;

   while (str[i] != '\0') {
      if ( str[i] != ' ' ||
            lastc != ' '   ) {
         str[j++] = str[i];
      }
      lastc = str[i];
      ++i;
   }
   str[j] = '\0';

TERMINATE:
   return error;
} /* End of PCMstrlbkstoblk*/

   int
PCMstrindex(char *str, char *substr, int *index)
{
   int error = 0;
   int i = 0;
   int j = 0;
   int k = 0;

   assert(str != NULL);
   assert(substr != NULL);

   *index = -1;
   for (i = 0; str[i] != '\0'; ++i) {
      for ( j = i, k = 0; (substr[k] != '\0') && (substr[k] == str[j]); ++j, ++k);

      if ( k > 0 && substr[k] == '\0' ) {
         *index = i;
         printf ("%s in %s at %d\n", substr, str, *index);
      }
   }

TERMINATE:
   return error;
} /* End of PCMstrindex*/

