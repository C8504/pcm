#include "PCMstack.h"

int main(void)
{
   int i = 0;
   int error = 0;
   int a[5] = {1, 3, 4, 5, 2};
   float b[5] = {1.0, 3.0, 4.0, 5.0, 2.0};
   char c[5] = {'a', 'b', 'c', 'd', '\0'};
   char *strarr[5] = {"ab", "cd", "ef", "g", "h"};
   char *dynamicstrarr[5] = {0};

   void *p = NULL;

   PCMstack *s = NULL;

   CALL(PCMstackcreate (&s, 3));

   //integer
   printf ("integer stack:\n");
   for (i = 0; i < 5; ++i) {
      CALL(PCMstackpush (s, &a[i]));
   }
   for (i = 0; i < 5; ++i) {
      printf ("%5d", *(int*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%d is poped\n", *(int*)(PCMstackpop(s)));
   }

   if ( PCMstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }


   //float
   printf ("float stack:\n");
   for (i = 0; i < 5; ++i) {
      CALL(PCMstackpush (s, &b[i]));
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5.2f", *(float*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%.2f is poped\n", *(float*)(PCMstackpop(s)));
   }

   if ( PCMstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }


   //char
   printf ("char stack:\n");
   for (i = 0; i < 5; ++i) {
      CALL(PCMstackpush (s, &c[i]));
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5c", *(char*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%c is poped\n", *(char*)(PCMstackpop(s)));
   }

   if ( PCMstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }

   //strarray
   printf ("str array stack:\n");
   for (i = 0; i < 5; ++i) {
      CALL(PCMstackpush (s, strarr[i]));
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5s", (char*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%s is poped\n", (char*)(PCMstackpop(s)));
   }
   if ( PCMstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }

   //dynamic string array
   printf ("dynamic string array:\n");
   for (i = 0; i < 5; ++i) {
      dynamicstrarr[i] = malloc (sizeof(char*));
      strcpy(dynamicstrarr[i], strarr[i]);
   }
   for (i = 0; i < 5; ++i) {
      CALL(PCMstackpush (s, dynamicstrarr[i]));
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5s", (char*)s->data[i]);
   }
   putchar('\n');

   /*    for (i = 0; i < 5; ++i) { */
   /*       p = PCMstackpop(s); */
   /*       printf ("%s is poped\n", (char*)p); */
   /*       free (p); */
   /*    } */
   if ( PCMstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }

TERMINATE:
   PCMstackfree (&s, free);
   PCMcheckerror (error);
   return 0;
}
