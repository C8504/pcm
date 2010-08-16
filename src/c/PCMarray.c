/* sequence list by John Cui*/
#include "PCM.h"
#include "PCMsort.h"
#include "PCMfind.h"
#include "PCMarray.h"

int
PCMarrayinit (PCMarray **list)
{
   DERROR;

   PCM_ALLOC((*list), 1, (**list));
   
   PCM_ALLOC((*list)->elemp, PCMLISTINITSIZE, int);
   
   (*list)->length = 0;
   (*list)->capacity = PCMLISTINITSIZE;

   RETURN;
} /* End of PCMarrayinit */

/* Free the list*/
int
PCMarrayfree (PCMarray **list)
{
   DERROR;
   int temp = 0;

   assert(list != NULL);

   if ( (*list)->elemp != NULL) {
      while ((*list)->length != 0) {
         THROW(PCMarraydelete(*list, (*list)->length - 1, &temp));
      }
      
      PCM_FREE((*list)->elemp);
      (*list)->capacity = 0;
   }

   PCM_FREE(*list);

   RETURN;
} /* End of PCMarrayfree */

/* Copy an array to the list with count */
int
PCMarraycopy (PCMarray *list, const int *arr, int count)
{
   DERROR;
   int i;

   assert(list != NULL);
   assert(arr  != NULL);

   for (i = 0; i < count; ++i) {
      THROW(PCMarrayinsert(list, list->length, arr[i]));
   }
   
   RETURN;
} /* End of PCMarraycopy*/

/* Merge two listsand sort it*/
int
PCMarraymerge (PCMarray *des, const PCMarray* src)
{
   DERROR;
   int i;
   int index = -1;

   assert(des != NULL);
   assert(src != NULL);

   for (i = 0; i < src->length ; ++i) {
      THROW(PCMarrayinsert(des, des->length, src->elemp[i]));
   }

   THROW(PCMarraysort (des, des->length, 0));
   
   RETURN;
} /* End of PCMarraymerge*/

/* Clear the whole list*/
int
PCMarrayclear (PCMarray *list)
{
   DERROR;
   int temp = 0;

   while (list->length != 0) {
      THROW(PCMarraydelete(list, list->length - 1, &temp));
   }
   
   RETURN;
} /* End of PCMarrayclear*/

/* Insert an elem to the list with index*/
int
PCMarrayinsert (PCMarray *list,
      int index,
      const int elem)
{
   DERROR;
   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0            ||
        index > list->length   ) {
      THROW(PCMERRNOTVALIDINDEX);
   }

   assert(list->elemp != NULL);
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

   RETURN;
} /* END of PCMarrayinsert */

/* Delete an element in index, and save the deleted element to *e*/
int
PCMarraydelete (PCMarray *list,
      int index,
      int *e)
{
   DERROR;
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
   
   RETURN;
} /* End of PCMarraydelete */

/* Delete the repeat element in list */
int
PCMarraydeleteR(PCMarray *list)
{
   DERROR;
   int i, index, e;

   for (i = list->length; i > 0; --i) {
      THROW(PCMarrayfind(list, i-1, list->elemp[i-1], &index, 0));

      if ( index != -1 ) {
         THROW(PCMarraydelete (list, index, &e));
      }
   }
   
   RETURN;
} /* End of PCMarraydeleteR */

/* Output the list */
int
PCMarrayoutput (PCMarray *list)
{
   DERROR;
   int i;

   assert(list != NULL);

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

   RETURN;
} /* End of PCMarrayoutput */

/* Sort list by customize algorithm, bubble sort by default */
int
PCMarraysort (PCMarray *list,
      int length,
      enum PCMSORTALG alg)
{
   DERROR;
   assert(list != NULL);

   if (length > list->length) {
      length = list->length;
   }

   // take qsort as default alg
   if ( alg == PCMALGSORTSELECT) {
      THROW(PCMselectsort(list->elemp, length));
   }
   else if ( alg == PCMALGSORTBUBBLE ) {
      THROW(PCMbubblesort(list->elemp, list->length));
   }
   else if ( alg == PCMALGSORTQUICK ) {
      qsort(list->elemp, list->length, sizeof (int), PCMcompare);
   }
   else if ( alg == PCMALGSORTSHELL) {
      THROW(PCMshellsort (list->elemp, list->length));
   }
   else if ( alg == PCMALGSORTINSERT) {
      THROW(PCMinsertsort (list->elemp, list->length));
   }
   else {
      qsort(list->elemp, list->length, sizeof (int), PCMcompare);
   }

   RETURN;
} /* End of PCMsqlistsort */

/* Find element in list by customize algorithm, Origin Find by default */
int
PCMarrayfind (PCMarray *list,
      int length,
      const int elem,
      int *index,
      enum PCMSEARCHALG alg)
{
   DERROR;

   assert(list != NULL);

   *index = -1;

   if (length > list->length) {
      length = list->length;
   }

   // take PCMoriginfind as default alg
   if ( PCMALGORIGINFIND == alg ) {
      THROW(PCMoriginfind (list->elemp, length, elem, index));
   }
   else if ( PCMALGBINFIND == alg) {
      THROW(PCMbinfind (list->elemp, length, elem, index));
   }
   else {
      THROW(PCMoriginfind (list->elemp, length, elem, index));
   }

   RETURN;
} /* End of PCMarrayfind */

