/* linked list by John Cui*/
#include "PCMlinkedlist.h"

void
PCMnodefree (PCMlinkednode **node)
{
   if ( *node != NULL ) {
      if ( (*node)->elem != NULL ) {
         PCM_FREE ((*node)->elem);
      }
      PCM_FREE (*node);
   }
} /* End of PCMnodefree */

int
PCMnodeallocandinit (PCMlinkednode **node,
                     const char* elem)
{
   DERROR;

   PCM_ALLOC(*node, 1, **node);

   if ( elem != NULL ) {
      size_t ssize = 0;
      THROW(PCMstrlen (elem, &ssize));
      ++ssize;

      (*node)->elem = malloc (ssize);
      //memset ((*node)->elem, '\0', ssize);
      if ( NULL == (*node)->elem ) {
         // free *node if alloc elem failed.
         PCM_FREE (*node);

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

   RETURN;
} /* End of PCMnodeallocandinit */

int
PCMlinkedlistinit (PCMlinkedlist **list)
{
   DERROR;

   PCM_ALLOC(*list, 1, **list);

   (*list)->first = NULL;
   (*list)->last  = NULL;

   RETURN;
} /* End of PCMlinkedlistinit */


/* free the list*/
int
PCMlinkedlistfree (PCMlinkedlist **list)
{
   DERROR;
   PCMlinkednode *oldp = NULL;

   while ((*list)->first != NULL) {
      oldp = (*list)->first;
      (*list)->first = (*list)->first->next;
      PCMnodefree (&oldp);
   }
   (*list)->first = (*list)->last = NULL;
   PCM_FREE(*list);

   RETURN;
} /* End of PCMlinkedlistfree */

int
PCMlinkedlistappend (PCMlinkedlist *list,
                     const char* elem)
{
   DERROR;
   PCMlinkednode *newnode = NULL;

   THROW(PCMnodeallocandinit (&newnode, elem));

   if ( list->first == NULL &&
      list->last  == NULL  ) {
         list->last = list->first = newnode;
   }
   else {
      newnode->prev = list->last;
      list->last->next = newnode;
      list->last = newnode;
   }

   RETURN;
} /* END of PCMlinkedlistappend */

//insert the newnode after "p"
int
PCMlinkedlistinsert (PCMlinkedlist *list,
                     int         pos,
                     const char* elem)
{
   DERROR;
   int j = 0;
   int len = PCMlinkedlistlength(list);
   PCMlinkednode *p = list->first;
   PCMlinkednode *newnode = NULL;

   // If list is an empty list, then ignore pos
   // and the newnode is the list->first and list->last
   if ( len == 0 ) {
      THROW(PCMnodeallocandinit (&newnode, elem));
      list->first = list->last = newnode;
   }
   else {
      // if pos == len, then just append it
      if ( pos == len ) {
         THROW(PCMlinkedlistappend (list, elem));
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
         THROW(PCMnodeallocandinit (&newnode, elem));

         // insert the newnode after "p"
         newnode->next = p->next;
         newnode->prev = p;
         p->next = newnode;
      }
   }

   RETURN;
} /* End of PCMlinkedlistinsert */

int
PCMlinkedlistoutput (PCMlinkedlist *list,
                     const char* sp)
{
   DERROR;

   PCMlinkednode *p;

   assert(list);

   //printf ("\n++++++++++++++PCM_linked_list++++++++++++++++++++++++++++\n");

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
         printf ("There are %d elements in this list\n\n", PCMlinkedlistlength (list));
   }
   else {
      printf ("This is an empty list now\n\n");
   }

   //printf ("\n+++++++++++++++++++END+++++++++++++++++++++++++++++++++++\n");

   RETURN;
} /* End of PCMlinkedlistoutput */

int
PCMlinkedlistclear (PCMlinkedlist *list)
{
   DERROR;

   while (0 != PCMlinkedlistlength (list)) {
      THROW(PCMlinkedlistpop (list, PCMPOPSTACK));
   }

   RETURN;
} /* End of PCMlinkedlistclear */

// Pop is a method used in both stack and queue with type
int
PCMlinkedlistpop (PCMlinkedlist *list,
                  enum PCMPOPTYPE type)
{
   DERROR;
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

   PCM_FREE (p->elem);
   PCM_FREE (p);

   RETURN;
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

