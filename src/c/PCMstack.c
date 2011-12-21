#include "PCMstack.h"

int
PCMstackcreate (PCMstack **sp, size_t size)
{
   DERROR;

   if ( 0 == size )
   {
      *sp = NULL;
      goto TERMINATE;
   }

   if ( *sp == NULL )
   {
      PCM_ALLOC(*sp, 1, **sp);
      (*sp)->data = malloc (size * sizeof (void*));
      if ( (*sp)->data == NULL )
      {
         PCM_FREE (*sp);
         THROW(PCMERRNOMEMORY);
      }
      else
      {
         (*sp)->top  = -1;
         (*sp)->size = size;
         (*sp)->data[0] = NULL;
      }
   }

   RETURN;
} /* End of PCMstackcreate */

/* freefunc is used to free the dynamic momery which
* in (*sp)->data pointers array, if the pointer in (*sp)->data
* was allocated dynamicly, otherwise pass NULL to freefunc*/
void
PCMstackfree (PCMstack **sp, FREEFUNC freefunc)
{
   int i = 0;

   if ( *sp != NULL )
   {
      if ( (*sp)->data != NULL )
      {
         if ( freefunc != NULL )
         {
            for (i = 0; i < (*sp)->top; ++i)
            {
               (*freefunc)(((*sp)->data[i]));
               (*sp)->data[i] = NULL;
            }
         }
         PCM_FREE ((*sp)->data);
      }
      else
      {
         PCM_FREE (*sp);
      }
   }
} /* End of PCMstackfree */

int
PCMstackpush (PCMstack *s, void *elem)
{
   DERROR;

   if ( s == NULL )
   {
      elem = NULL;
   }
   else
   {
      if ( s->top >= s->size )
      {
         s->data = realloc (s->data, 2 * (s->size) * sizeof(void *));
         if ( s == NULL )
         {
            THROW(PCMERRNOMEMORY);
         }
         else
         {
            s->size *= 2;
         }
      }
      s->top++;
      s->data[s->top] = elem;
   }

   RETURN;
} /* End of PCMstackpush */

void*
PCMstackpop (PCMstack *s)
{
   void *elem;

   if( s == NULL || s->top == -1)
   {
      elem = NULL;
   }
   else
   {
      elem = s->data[s->top];
      s->top--;
   }

   return elem;
} /* End of PCMstackpop */

int
PCMstackisempty (PCMstack *s)
{
   if( s == NULL || s->top == -1 )
   {
      return TRUE;
   }
   return FALSE;
} /* End of PCMstackisempty */

