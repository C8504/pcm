/* linked list by John Cui*/
#include "PCMlinkedlist.h"

void
PCMnodefree (PCMlinkednode **node)
{
   if ( *node != NULL ) {
      if ( (*node)->elem != NULL ) {
         free ((*node)->elem);
         (*node)->elem = NULL;
      }
      free (*node);
      *node = NULL;
   }
} /* End of PCMnodefree */

int
PCMnodeallocandinit (PCMlinkednode **node,
      const char* elem)
{
   int error = 0;

   *node = malloc (sizeof **node);
   if ( NULL == *node ) {
      THROW(PCMERRNOMEMORY);
   }

   if ( elem != NULL ) {
      size_t ssize = 0;
      error = PCMstrlen (elem, &ssize);
      if ( error ) {
         THROW(error);
      }
      ++ssize;

      (*node)->elem = malloc (ssize);
      //memset ((*node)->elem, '\0', ssize);
      if ( NULL == (*node)->elem ) {
         // free *node if alloc elem failed.
         free (*node);
         *node = NULL;

         THROW(PCMERRNOMEMORY);
      }
      else {
         //strncat ((*node)->elem, elem, strlen(elem));
         //memcpy ((*node)->elem, elem, ssize);
         PCMstrncpy ((*node)->elem, elem, ssize);
      }
   }
   else {
      (*node)->elem = NULL;
   }

   (*node)->next = NULL;
   (*node)->prev = NULL;

TERMINATE:
   return error;
} /* End of PCMnodeallocandinit */

int
PCMlinkedlistinit (PCMlinkedlist **list)
{
   int error = 0;

   *list = malloc (sizeof **list);
   if ( NULL == *list ) {
      THROW(PCMERRNOMEMORY);
   }

   (*list)->first = NULL;
   (*list)->last  = NULL;

TERMINATE:

   return error;
} /* End of PCMlinkedlistinit */


/* free the list*/
int
PCMlinkedlistfree (PCMlinkedlist **list)
{
   int error = 0;
   PCMlinkednode *oldp = NULL;

   while ((*list)->first != NULL) {
      oldp = (*list)->first;
      (*list)->first = (*list)->first->next;
      PCMnodefree (&oldp);
   }
   (*list)->first = (*list)->last = NULL;
   free (*list);
   *list = NULL;

   return error;
} /* End of PCMlinkedlistfree */

int
PCMlinkedlistappend (PCMlinkedlist *list,
      const char* elem)
{
   PCMlinkednode *newnode = NULL;

   int error = PCMnodeallocandinit (&newnode, elem);
   if ( error ) {
      THROW(error);
   }

   if ( list->first == NULL &&
         list->last  == NULL  ) {
      list->last = list->first = newnode;
   }
   else {
      newnode->prev = list->last;
      list->last->next = newnode;
      list->last = newnode;
   }

TERMINATE:

   return error;
} /* END of PCMlinkedlistappend */

//insert the newnode after "p"
int
PCMlinkedlistinsert (PCMlinkedlist *list,
      int         pos,
      const char* elem)
{
   int error;
   int j = 0;
   int len = PCMlinkedlistlength(list);
   PCMlinkednode *p = list->first;
   PCMlinkednode *newnode = NULL;

   // If list is an empty list, then ignore pos
   // and the newnode is the list->first and list->last
   if ( len == 0 ) {
      error = PCMnodeallocandinit (&newnode, elem);
      if ( error ) {
         THROW(error);
      }
      list->first = list->last = newnode;
   }
   else {
      // if pos == len, then just append it
      if ( pos == len ) {
         error = PCMlinkedlistappend (list, elem);
         if ( error )  {
            THROW(error);
         }
      }
      // if pos in the middle of list
      else {
         // check pos
         if ( pos < 1  ||
              pos > len  ) {
            THROW(PCMERRNOTVALIDINDEX);
         }

         // find the node at pos "p"
         while (p && j < pos-1) {
            p = p->next;
            ++j;
         }

         // creat newnode
         error = PCMnodeallocandinit (&newnode, elem);
         if ( error ) {
            THROW(error)
         }

         // insert the newnode after "p"
         newnode->next = p->next;
         newnode->prev = p;
         p->next = newnode;
      }
   }

TERMINATE:
   return error;
} /* End of PCMlinkedlistinsert */

int
PCMlinkedlistoutput (PCMlinkedlist *list,
      const char* sp)
{
   int error = 0;

   PCMlinkednode *p;

   if ( list == NULL ) {
      THROW(PCMERRNULLPOINTER);
   }
   
   printf ("\n++++++++++++++PCM_linked_list++++++++++++++++++++++++++++\n");
   
   if ( list->first != NULL &&
         list->last  != NULL   ) {
      p = list->first;
      while ( p != NULL) {
         if ( sp != NULL ) {
            printf ("%s%s", p->elem, sp);
         }
         else {
            printf ("%s", p->elem);
         }
         p = p->next;
      }
      printf ("\n");
      printf ("Have %d elements in this list\n\n", PCMlinkedlistlength (list));
   }
   else {
      printf ("This is an empty list now\n\n");
   }

   printf ("\n+++++++++++++++++++END+++++++++++++++++++++++++++++++++++\n");

TERMINATE:
   return error;
} /* End of PCMlinkedlistoutput */

int
PCMlinkedlistclear (PCMlinkedlist *list)
{
   int error = 0;

   while (0 != PCMlinkedlistlength (list)) {
      error = PCMlinkedlistpop (list, PCMPOPSTACK);
      if ( error )  {
         THROW(error);
      }
   }

TERMINATE:
   return error;
} /* End of PCMlinkedlistclear */

// Pop is a method used in both stack and queue with type 
int
PCMlinkedlistpop (PCMlinkedlist *list,
      enum PCMPOPTYPE type)
{
   int error = 0;
   PCMlinkednode *p = NULL;

   if ( type == PCMPOPQUEUE ) {
      if ( list->first != NULL ) {
         p = list->first;

         // If more than one elememt
         if ( list->first->next != NULL ) {
            list->first = list->first->next;
            list->first->prev = NULL;
         }
         // If only one element
         else {
            list->first = NULL;
            list->last = NULL;
         }
      }
      else {
         THROW(PCMERREMPTYLIST);
      }
   }
   else if ( type == PCMPOPSTACK ) {
      if ( list->last != NULL ) {
         p = list->last;

         if ( list->last->prev != NULL ) {
            list->last = list->last->prev;
            list->last->next = NULL;
         }
         else {
            list->first = NULL;
            list->last = NULL;
         }
      }
      else {
         THROW(PCMERREMPTYLIST);
      }
   }
   else {
      THROW(PCMERRNOTSTACKANDQUEUE);
   }

   free (p->elem);
   free (p);

TERMINATE:
   return error;
} /* End of PCMlinkedlistpop */

int
PCMlinkedlistlength(PCMlinkedlist *list)
{
   int length = 0;
   PCMlinkednode *p = list->first;

   while (p != NULL) {
      ++length;
      p = p->next;
   }

   return length;
} /* END of PCMlinkedlistlength */

