#include "ORCstack.h"

int
ORCstackcreate (ORCstack **sp, size_t size){
   int error = 0;

   if ( 0 == size ) {
      *sp = NULL;
      goto TERMINATE;
   }

   if ( *sp == NULL ) {
      *sp = malloc (sizeof (**sp));
      if ( *sp == NULL ) {
         error = ORCERRNOMEMORY;
         goto TERMINATE;
      }
      else {
         (*sp)->data = malloc (size * sizeof (void*));
         if ( (*sp)->data == NULL ) {
            error = ORCERRNOMEMORY;
            free (*sp);
            *sp = NULL;
            goto TERMINATE;
         }
         else {
            (*sp)->top  = -1;
            (*sp)->size = size;
            (*sp)->data[0] = NULL;
         }
      }
   }

TERMINATE:
   return error;
} /* End of ORCstackcreate */

/* freefunc is used to free the dynamic momery which
 * in (*sp)->data pointers array, if the pointer in (*sp)->data
 * was allocated dynamicly, otherwise pass NULL to freefunc*/
   void
ORCstackfree (ORCstack **sp, FREEFUNC freefunc)
{
   int i = 0;

   if ( *sp != NULL ) {
      if ( (*sp)->data != NULL ) {
         if ( freefunc != NULL ) {
            for (i = 0; i < (*sp)->top; ++i){
               (*freefunc)(((*sp)->data[i]));
               (*sp)->data[i] = NULL;
            }
         }
         free ((*sp)->data);
         (*sp)->data = NULL;
      }
      else {
         free (*sp);
         *sp = NULL;
      }
   }
} /* End of ORCstackfree */

   int 
ORCstackpush (ORCstack *s, void *elem)
{
   int error = 0;

   if ( s == NULL ) {
      elem = NULL;
   }
   else {
      if ( s->top >= s->size ) {
         s->data = realloc (s->data, 2 * (s->size) * sizeof(void *));
         if ( s == NULL ) {
            error = ORCERRNOMEMORY;
            goto TERMINATE;
         }
         else {
            s->size *= 2;
         }
      }
      s->top++;
      s->data[s->top] = elem;
   }

TERMINATE:
   return error;
} /* End of ORCstackpush */

   void*
ORCstackpop (ORCstack *s)
{
   void *elem;

   if( s == NULL || s->top == -1) {
      elem = NULL;
   }
   else {
      elem = s->data[s->top];
      s->top--;
   }

   return elem;
} /* End of ORCstackpop */

   int
ORCstackisempty (ORCstack *s)
{
   if( s == NULL || s->top == -1 ){
      return TRUE;
   }
   return FALSE;
} /* End of ORCstackisempty */

