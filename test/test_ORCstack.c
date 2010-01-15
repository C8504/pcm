#include "ORCstack.h"

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

   ORCstack *s = NULL;

   error = ORCstackcreate (&s, 3);

   if( error ) {
      goto TERMINATE;
   }

   //integer
   printf ("integer stack:\n");
   for (i = 0; i < 5; ++i) {
      error = ORCstackpush (s, &a[i]);
      if ( error )  goto TERMINATE;
   }
   for (i = 0; i < 5; ++i) {
      printf ("%5d", *(int*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%d is poped\n", *(int*)(ORCstackpop(s)));
   }

   if ( ORCstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }


   //float
   printf ("float stack:\n");
   for (i = 0; i < 5; ++i) {
      error = ORCstackpush (s, &b[i]);
      if ( error )  goto TERMINATE;
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5.2f", *(float*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%.2f is poped\n", *(float*)(ORCstackpop(s)));
   }

   if ( ORCstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }


   //char
   printf ("char stack:\n");
   for (i = 0; i < 5; ++i) {
      error = ORCstackpush (s, &c[i]);
      if ( error )  goto TERMINATE;
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5c", *(char*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%c is poped\n", *(char*)(ORCstackpop(s)));
   }

   if ( ORCstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }

   //strarray
   printf ("str array stack:\n");
   for (i = 0; i < 5; ++i) {
      error = ORCstackpush (s, strarr[i]);
      if ( error )  goto TERMINATE;
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5s", (char*)s->data[i]);
   }
   putchar('\n');

   for (i = 0; i < 5; ++i) {
      printf ("%s is poped\n", (char*)(ORCstackpop(s)));
   }
   if ( ORCstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }

   //dynamic string array
   printf ("dynamic string array:\n");
   for (i = 0; i < 5; ++i) {
      dynamicstrarr[i] = malloc (sizeof(char*));
      strcpy(dynamicstrarr[i], strarr[i]);
   }
   for (i = 0; i < 5; ++i) {
      error = ORCstackpush (s, dynamicstrarr[i]);
      if ( error )  goto TERMINATE;
   }

   for (i = 0; i < 5; ++i) {
      printf ("%5s", (char*)s->data[i]);
   }
   putchar('\n');

   /*    for (i = 0; i < 5; ++i) { */
   /*       p = ORCstackpop(s); */
   /*       printf ("%s is poped\n", (char*)p); */
   /*       free (p); */
   /*    } */
   if ( ORCstackisempty(s) ) {
      printf ("stack is empty now!\n");
   }

TERMINATE:
   ORCstackfree (&s, free);
   ORCcheckerror (error);
   return 0;
}
