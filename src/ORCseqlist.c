/* sequence list by John Cui*/
#include "ORC.h"
#include "ORCsort.h"
#include "ORCfind.h"
#include "ORCseqlist.h"

int
ORCseqlistinit (ORCseqlist **list)
{
   int error = 0;

   *list = malloc(sizeof **list);
   if ( *list == NULL ) {
      error = ORCERRNOMEMORY;
      goto TERMINATE;
   }
   (*list)->elemp = malloc(ORCLISTINITSIZE * sizeof(int));
   if ( (*list)->elemp == NULL ) {
      error = ORCERRNOMEMORY;
      goto TERMINATE;
   }
   (*list)->length = 0;
   (*list)->capacity = ORCLISTINITSIZE;

TERMINATE:

   return error;
} /* End of ORCseqlistinit */

/* Free the list*/
int
ORCseqlistfree (ORCseqlist **list)
{
   int error = 0;
   int temp = 0;

   if ( NULL == list ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   if ( (*list)->elemp != NULL) {
      while ((*list)->length != 0) {
         error = ORCseqlistdelete(*list, 0, &temp);
         if ( error != 0 )  goto TERMINATE;
      }
      free((*list)->elemp);
      (*list)->elemp = NULL;
      (*list)->capacity = 0;
   }

   free (*list);
   *list = NULL;

TERMINATE:

   return error;
} /* End of ORCseqlistfree */

/* Copy an array to the list with count */
int
ORCseqlistcopy (ORCseqlist *list, const int *arr, int count)
{
   int i;
   int error = 0;

   if ( NULL == list || NULL == arr) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   for (i = 0; i < count; ++i) {
      error = ORCseqlistinsert(list, list->length, arr[i]);
      if ( error != 0 )  goto TERMINATE;
   }

TERMINATE:

   return error;
} /* End of ORCseqlistcopy*/

/* Merge two lists */
int
ORCseqlistmerge (ORCseqlist *des, const ORCseqlist* src)
{
   int i;
   int error = 0;
   int index = -1;

   if ( NULL == des || NULL == src) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   for (i = 0; i < src->length ; ++i) {
      error = ORCseqlistinsert(des, des->length, src->elemp[i]);
      if ( error != 0 )  goto TERMINATE;
   }

   error = ORCseqlistsort (des, des->length, 0);
   if ( error )  goto TERMINATE;

TERMINATE:

   return error;
} /* End of ORCseqlistmerge*/

/* Clear the whole list*/
int
ORCseqlistclear (ORCseqlist *list)
{
   int error = 0;
   int temp = 0;

   while (list->length != 0) {
      error = ORCseqlistdelete(list, 0, &temp);
      if ( error != 0 )  goto TERMINATE;
   }

TERMINATE:

   return error;
} /* End of ORCseqlistclear*/

/* Insert an elem to the list with index*/
int
ORCseqlistinsert (ORCseqlist *list,
                  int index,
                  const int elem)
{
   int error = 0;

   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0            ||
      index > list->length   ) {
         error = ORCERRNOTVALIDINDEX;
         goto TERMINATE;
   }

   assert (list->elemp != NULL);
   //extend capacity if length >= capacity in realloc
   if ( list-> length == list->capacity) {
      list->elemp =
         (int*) realloc (list->elemp,
         sizeof (int) * (list->capacity + ORCLISTINCREMENT));
      if ( list->elemp == NULL ) {
         error = ORCERRNOMEMORY;
         goto TERMINATE;
      }
      list->capacity += ORCLISTINCREMENT;
   }

   //move elements which is after list[index] to next
   p = &(list->elemp[index]);
   for (q = &(list->elemp[list->length - 1]); q >= p; --q) {
      *(q+1) = *q;
   }

   //insert elem and increase the length of list
   *p = elem;
   ++list->length;

TERMINATE:

   return error;
} /* END of ORCseqlistinsert */

/* Delete an element in index, and save the deleted element to *e*/
int
ORCseqlistdelete (ORCseqlist *list,
                  int index,
                  int *e)
{
   int error = 0;

   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0              ||
      index > list->length - 1   ) {
         error = ORCERRNOTVALIDINDEX;
         goto TERMINATE;
   }

   //keep the deleted element
   *e = list->elemp[index];

   //move the element which after list[index] to previous
   p = &list->elemp[index];
   for (q = p; q <= &(list->elemp[list->length-1]); ++q) {
      *q = *(q+1);
   }
   --list->length;

TERMINATE:

   return error;
} /* End of ORCseqlistdelete */

/* Delete the repeat element in list */
int
ORCseqlistdeleteR(ORCseqlist *list)
{
   int error = 0;
   int i, index, e;

   for (i = list->length; i > 0; --i) {
      error = ORCseqlistfind(list, i-1, list->elemp[i-1], &index, 0);
      if ( error != 0 )  goto TERMINATE;

      if ( index != -1 ) {
         error = ORCseqlistdelete (list, index, &e);
         if ( error != 0 )  goto TERMINATE;
      }
   }

TERMINATE:

   return error;

} /* End of ORCseqlistdeleteR */

/* Output the list */
int
ORCseqlistoutput (ORCseqlist *list)
{
   int i;
   int error = 0;

   if ( NULL == list ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   printf ("list->length = %d\n", list->length);
   printf ("list->capacity = %d\n", list->capacity);

   if ( list->length != 0 ) {
      printf ("elements:\n");
      for (i = 0; i < list->length; ++i) {
         printf ("%d ", list->elemp[i]);
      }
   }
   else {
      printf("This is a NULL list!");
   }
   printf ("\n\n");

TERMINATE:

   return error;
} /* End of ORCseqlistoutput */

/* Sort list by customize algorithm, bubble sort by default */
int
ORCseqlistsort (ORCseqlist *list,
                int length,
                enum ORCSORTALG alg)
{
   int error = 0;

   if ( NULL == list ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   if (length > list->length) {
      length = list->length;
   }

   // take ORCbubblesort as default alg
   if ( alg == ORCALGSORTSELECT) {
      ORCselectsort(list->elemp, length);
   }
   else if ( ORCALGSORTBUBBLE ) {
      ORCbubblesort(list->elemp, list->length);
   }
   else {
      ORCbubblesort(list->elemp, list->length);
   }

TERMINATE:

   return error;
}

/* Find element in list by customize algorithm, Origin Find by default */
int
ORCseqlistfind (ORCseqlist *list,
                int length,
                const int elem,
                int *index,
                enum ORCSEARCHALG alg)
{
   int error = 0;

   if ( NULL == list ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   *index = -1;

   if (length > list->length) {
      length = list->length;
   }

   // take ORCoriginfind as default alg
   if ( ORCALGORIGINFIND == alg ) {
      ORCoriginfind (list->elemp, length, elem, index);
   }
   /*else if () {
   }*/
   else {
      ORCoriginfind (list->elemp, length, elem, index);
   }

TERMINATE:

   return error;
} /* End of ORCseqlistfind */
