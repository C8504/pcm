/* sequence list by John Cui*/
#include "PCM.h"
#include "PCMsort.h"
#include "PCMfind.h"
#include "PCMseqlist.h"

int
PCMseqlistinit (PCMseqlist **list)
{
   int error = 0;

   *list = malloc(sizeof **list);
   if ( *list == NULL ) {
      THROW(PCMERRNOMEMORY);
   }
   (*list)->elemp = malloc(PCMLISTINITSIZE * sizeof(int));
   if ( (*list)->elemp == NULL ) {
      THROW(PCMERRNOMEMORY);
   }
   (*list)->length = 0;
   (*list)->capacity = PCMLISTINITSIZE;

TERMINATE:
   return error;
} /* End of PCMseqlistinit */

/* Free the list*/
int
PCMseqlistfree (PCMseqlist **list)
{
   int error = 0;
   int temp = 0;

   if ( NULL == list ) {
      THROW(PCMERRNULLPOINTER);
   }

   if ( (*list)->elemp != NULL) {
      while ((*list)->length != 0) {
         error = PCMseqlistdelete(*list, (*list)->length - 1, &temp);
         if ( error )  {
            THROW(error);
         }
      }
      free((*list)->elemp);
      (*list)->elemp = NULL;
      (*list)->capacity = 0;
   }

   free (*list);
   *list = NULL;

TERMINATE:
   return error;
} /* End of PCMseqlistfree */

/* Copy an array to the list with count */
int
PCMseqlistcopy (PCMseqlist *list, const int *arr, int count)
{
   int i;
   int error = 0;

   if ( NULL == list || NULL == arr) {
      THROW(PCMERRNULLPOINTER);
   }

   for (i = 0; i < count; ++i) {
      error = PCMseqlistinsert(list, list->length, arr[i]);
      if ( error ) {
         THROW(error);
      }
   }

TERMINATE:
   return error;
} /* End of PCMseqlistcopy*/

/* Merge two lists */
int
PCMseqlistmerge (PCMseqlist *des, const PCMseqlist* src)
{
   int i;
   int error = 0;
   int index = -1;

   if ( NULL == des || NULL == src) {
      THROW(PCMERRNULLPOINTER);
   }

   for (i = 0; i < src->length ; ++i) {
      error = PCMseqlistinsert(des, des->length, src->elemp[i]);
      if ( error ) {
         THROW(error);
      }
   }

   error = PCMseqlistsort (des, des->length, 0);
   if ( error ) {
      THROW(error);
   }

TERMINATE:
   return error;
} /* End of PCMseqlistmerge*/

/* Clear the whole list*/
int
PCMseqlistclear (PCMseqlist *list)
{
   int error = 0;
   int temp = 0;

   while (list->length != 0) {
      error = PCMseqlistdelete(list, list->length - 1, &temp);
      if ( error )  {
         THROW(error);
      }
   }

TERMINATE:
   return error;
} /* End of PCMseqlistclear*/

/* Insert an elem to the list with index*/
int
PCMseqlistinsert (PCMseqlist *list,
      int index,
      const int elem)
{
   int error = 0;

   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0            ||
        index > list->length   ) {
      THROW(PCMERRNOTVALIDINDEX);
   }

   assert (list->elemp != NULL);
   //extend capacity if length >= capacity in realloc
   if ( list-> length == list->capacity) {
      list->elemp =
         (int*) realloc (list->elemp,
               sizeof (int) * (list->capacity + PCMLISTINCREMENT));
      if ( list->elemp == NULL ) {
         THROW(PCMERRNOMEMORY);
      }
      list->capacity += PCMLISTINCREMENT;
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
} /* END of PCMseqlistinsert */

/* Delete an element in index, and save the deleted element to *e*/
int
PCMseqlistdelete (PCMseqlist *list,
      int index,
      int *e)
{
   int error = 0;

   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0              ||
        index > list->length - 1   ) {
      THROW(PCMERRNOTVALIDINDEX);
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
} /* End of PCMseqlistdelete */

/* Delete the repeat element in list */
int
PCMseqlistdeleteR(PCMseqlist *list)
{
   int error = 0;
   int i, index, e;

   for (i = list->length; i > 0; --i) {
      error = PCMseqlistfind(list, i-1, list->elemp[i-1], &index, 0);
      if ( error )  {
         THROW(error);
      }

      if ( index != -1 ) {
         error = PCMseqlistdelete (list, index, &e);
         if ( error ) {
            THROW(error);
         }
      }
   }

TERMINATE:
   return error;
} /* End of PCMseqlistdeleteR */

/* Output the list */
int
PCMseqlistoutput (PCMseqlist *list)
{
   int i;
   int error = 0;

   if ( NULL == list ) {
      THROW(PCMERRNULLPOINTER);
   }

   printf ("\n++++++++++++++++PCM_sq_list+++++++++++++++++++++\n");
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
   printf ("\n++++++++++++++++END+++++++++++++++++++++++++++++\n");

TERMINATE:
   return error;
} /* End of PCMseqlistoutput */

/* Sort list by customize algorithm, bubble sort by default */
int
PCMseqlistsort (PCMseqlist *list,
      int length,
      enum PCMSORTALG alg)
{
   int error = 0;

   if ( NULL == list ) {
      THROW(PCMERRNULLPOINTER);
   }

   if (length > list->length) {
      length = list->length;
   }

   // take qsort as default alg
   if ( alg == PCMALGSORTSELECT) {
      error = PCMselectsort(list->elemp, length);
   }
   else if ( alg == PCMALGSORTBUBBLE ) {
      error = PCMbubblesort(list->elemp, list->length);
   }
   else if ( alg == PCMALGSORTQUICK ) {
      qsort(list->elemp, list->length, sizeof (int), PCMcompare);
   }
   else if ( alg == PCMALGSORTSHELL) {
      error = PCMshellsort (list->elemp, list->length);
   }
   else if ( alg == PCMALGSORTINSERT) {
      error = PCMinsertsort (list->elemp, list->length);
   }
   else {
      THROW(PCMERRWRONGSORTALG);
   }

TERMINATE:
   return error;
} /* End of PCMsqlistsort */

/* Find element in list by customize algorithm, Origin Find by default */
int
PCMseqlistfind (PCMseqlist *list,
      int length,
      const int elem,
      int *index,
      enum PCMSEARCHALG alg)
{
   int error = 0;

   if ( NULL == list ) {
      THROW(PCMERRNULLPOINTER);
   }

   *index = -1;

   if (length > list->length) {
      length = list->length;
   }

   // take PCMoriginfind as default alg
   if ( PCMALGORIGINFIND == alg ) {
      error = PCMoriginfind (list->elemp, length, elem, index);
   }
   else if ( PCMALGBINFIND == alg) {
      error = PCMbinfind (list->elemp, length, elem, index);
   }
   else {
      error = PCMoriginfind (list->elemp, length, elem, index);
   }

TERMINATE:
   return error;
} /* End of PCMseqlistfind */

