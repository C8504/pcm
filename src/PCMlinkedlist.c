/* linked list by John Cui*/
#include "ORClinkedlist.h"

   void
ORCnodefree (ORClinkednode **node)
{
   if ( *node != NULL ) {
      if ( (*node)->elem != NULL ) {
         free ((*node)->elem);
         (*node)->elem = NULL;
      }
      free (*node);
      *node = NULL;
   }
} /* End of ORCnodefree */

   int
ORCnodeallocandinit (ORClinkednode **node,
      const char* elem)
{
   int error = 0;

   *node = malloc (sizeof **node);
   if ( NULL == *node ) {
      error = ORCERRNOMEMORY;
      goto TERMINATE;
   }

   if ( elem != NULL ) {
      size_t ssize = 0;
      error = ORCstrlen (elem, &ssize);
      if ( error )  goto TERMINATE;
      ++ssize;

      (*node)->elem = malloc (ssize);
      //memset ((*node)->elem, '\0', ssize);
      if ( NULL == (*node)->elem ) {
         // free *node if alloc elem failed.
         free (*node);
         *node = NULL;

         error = ORCERRNOMEMORY;
         goto TERMINATE;
      }
      else {
         //strncat ((*node)->elem, elem, strlen(elem));
         //memcpy ((*node)->elem, elem, ssize);
         ORCstrncpy ((*node)->elem, elem, ssize);
      }
   }
   else {
      (*node)->elem = NULL;
   }

   (*node)->next = NULL;
   (*node)->prev = NULL;

TERMINATE:
   return error;
} /* End of ORCnodeallocandinit */

   int
ORClinkedlistinit (ORClinkedlist **list)
{
   int error = 0;

   *list = malloc (sizeof **list);
   if ( NULL == *list ) {
      error = ORCERRNOMEMORY;
      goto TERMINATE;
   }

   (*list)->first = NULL;
   (*list)->last  = NULL;

TERMINATE:

   return error;
} /* End of ORClinkedlistinit */


/* free the list*/
   int
ORClinkedlistfree (ORClinkedlist **list)
{
   int error = 0;
   ORClinkednode *oldp = NULL;

   while ((*list)->first != NULL) {
      oldp = (*list)->first;
      (*list)->first = (*list)->first->next;
      ORCnodefree (&oldp);
   }
   (*list)->first = (*list)->last = NULL;
   free (*list);
   *list = NULL;

   return error;
} /* End of ORClinkedlistfree */

   int
ORClinkedlistappend (ORClinkedlist *list,
      const char* elem)
{
   ORClinkednode *newnode = NULL;

   int error = ORCnodeallocandinit (&newnode, elem);
   if ( error )  goto TERMINATE;

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
} /* END of ORClinkedlistappend */

//insert the newnode after "p"
   int
ORClinkedlistinsert (ORClinkedlist *list,
      int         pos,
      const char* elem)
{
   int error;
   int j = 0;
   int len = ORClinkedlistlength(list);
   ORClinkednode *p = list->first;
   ORClinkednode *newnode = NULL;

   // If list is an empty list, then ignore pos
   // and the newnode is the list->first and list->last
   if ( len == 0 ) {
      error = ORCnodeallocandinit (&newnode, elem);
      if ( error )  goto TERMINATE;
      list->first = list->last = newnode;
   }
   else {
      // if pos == len, then just append it
      if ( pos == len ) {
         error = ORClinkedlistappend (list, elem);
         if ( error )  goto TERMINATE;
      }
      // if pos in the middle of list
      else {
         // check pos
         if ( pos < 1  ||
               pos > len  ) {
            error = ORCERRNOTVALIDINDEX;
            goto TERMINATE;
         }

         // find the node at pos "p"
         while (p && j < pos-1) {
            p = p->next;
            ++j;
         }

         // creat newnode
         error = ORCnodeallocandinit (&newnode, elem);
         if ( error )  goto TERMINATE;

         // insert the newnode after "p"
         newnode->next = p->next;
         newnode->prev = p;
         p->next = newnode;
      }
   }

TERMINATE:
   return error;
} /* End of ORClinkedlistinsert */

   int
ORClinkedlistoutput (ORClinkedlist *list,
      const char* sp)
{
   int error = 0;

   ORClinkednode *p;

   if ( list == NULL ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

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
      printf ("Have %d elements in this list\n\n", ORClinkedlistlength (list));
   }
   else {
      printf ("This is an empty list now\n\n");
   }

TERMINATE:
   return error;
} /* End of ORClinkedlistoutput */

   int
ORClinkedlistclear (ORClinkedlist *list)
{
   int error = 0;

   while (0 != ORClinkedlistlength (list)) {
      error = ORClinkedlistpop (list, ORCPOPSTACK);
      if ( error )  goto TERMINATE;
   }

TERMINATE:
   return error;
} /* End of ORClinkedlistclear */

// Pop is a method used in both stack and queue with type 
   int
ORClinkedlistpop (ORClinkedlist *list,
      enum ORCPOPTYPE type)
{
   int error = 0;
   ORClinkednode *p = NULL;

   if ( type == ORCPOPQUEUE ) {
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
         error = ORCERREMPTYLIST;
         goto TERMINATE;
      }
   }
   else if ( type == ORCPOPSTACK ) {
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
         error = ORCERREMPTYLIST;
         goto TERMINATE;
      }
   }
   else {
      error = ORCERRNOTSTACKANDQUEUE;
      goto TERMINATE;
   }

   free (p->elem);
   free (p);

TERMINATE:
   return error;
} /* End of ORClinkedlistpop */

   int
ORClinkedlistlength(ORClinkedlist *list)
{
   int length = 0;
   ORClinkednode *p = list->first;

   while (p != NULL) {
      ++length;
      p = p->next;
   }

   return length;
} /* END of ORClinkedlistlength */

