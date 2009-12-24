// using splint to check bounds
// splint test.c +bounds
#include<stdio.h>
#include<string.h>

#define IN 1
#define OUT 0

#define WORDCOUNT 1000
#define DIGIT 10
#define LENOFFILENAME 20

/*
   show level:
1: show less
2: show more
3: show all
*/

typedef struct statistics{
   char filename[LENOFFILENAME];
   int nword  ;
   int ndigit ;
   int nline  ;
   int nchar  ;
} STATISTICS;

int
readfile (const char *filename, int show){
   int i = 0;
   int j = 0;
   int c = 0;
   STATISTICS s = { "", 0, 0, 0, 0 };

   int digit[DIGIT] = {0};
   int lenofword[WORDCOUNT] = {0};

   FILE *fp = NULL;
   int state = OUT;

   if ( (filename != NULL                 )  &&
         (strlen (filename) < LENOFFILENAME))  {
      strcpy (s.filename, filename);
      s.filename[LENOFFILENAME-1] = '\0';
   }

   fp  = fopen (filename, "r");
   if ( fp == NULL ) return 1;

   //while ((c = getchar()) != EOF) {
   while ((c = getc(fp)) != EOF) {
      ++s.nchar;

      if ( '\n' == c ) {
         ++s.nline;
      }
      if ( c >= '0' && c <= '9') {
         ++s.ndigit;
         ++digit[c - '0'];
      }

      if ( ( (c >= 91)  && (c <= 96)  )  ||
            ( (c >= 0)   && (c <= 64)  )  ||
            ( (c >= 123) && (c <= 127) ) )  {
         state = OUT;
      }
      else if (OUT == state) {
         state = IN;
         ++s.nword;
      }

      if ( show == 3 ) {
         if (IN == state) {
            if ( s.nword <= WORDCOUNT ){
               ++lenofword[s.nword - 1];
            }
            else {
               printf ("Error: Words count exceed words count limit(%d)\n", WORDCOUNT);
               exit (1);
            }
         }
      }
   }
   fclose(fp);

   switch (show) {
      case 3:
         for (i = 0; i < s.nword; ++i) {
            for (j = 0; j < lenofword[i]; ++j) {
               printf("*");
            }
            printf ("\n");
         }

      case 2:
         if ( s.ndigit ) {
            for (i = 0; i < 10; ++i) {
               printf ("%d -> %d times \n", i, digit[i]);
            }
         }

      case 1:
         printf ("%d char\n", s.nchar);
         printf ("%d lines\n", s.nline);
         printf ("%d words\n", s.nword);
         printf ("%d digits\n", s.ndigit);

      default:
         printf ("%s was read\n", s.filename);
         printf ("************************\n");
   }

   return 0;
}

   int
main(void)
{
   if ( readfile ("..\\test\\getchar.c", 3) ) {
      exit(1);
   }
}
