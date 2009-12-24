/* sequence list by John Cui*/
#include "ORC.h"
#include "sort.h"
#include "find.h"
#include "seqlist.h"

   int
ORCSeqList_Init (ORCSeqList **list)
{
   int error = 0;

   *list = malloc(sizeof **list);
   if ( *list == NULL ) {
      error = ORCERR_NO_MEMORY;
      goto TERMINATE;
   }
   (*list)->elem_p = malloc(ORC_LIST_INIT_SIZE * sizeof(int));
   if ( (*list)->elem_p == NULL ) {
      error = ORCERR_NO_MEMORY;
      goto TERMINATE;
   }
   (*list)->length = 0;
   (*list)->capacity = ORC_LIST_INIT_SIZE;

TERMINATE:

   return error;
} /* End of ORCSeqList_Init */

/* Free the list*/
   int
ORCSeqList_Free (ORCSeqList **list)
{
   int error = 0;
   int temp = 0;

   if ( NULL == list ) {
      error = ORCERR_NULL_POINTER;
      goto TERMINATE;
   }

   if ( (*list)->elem_p != NULL) {
      while ((*list)->length != 0) {
         error = ORCSeqList_Delete(*list, 0, &temp);
         if ( error != 0 )  goto TERMINATE;
      }
      free((*list)->elem_p);
      (*list)->elem_p = NULL;
      (*list)->capacity = 0;
   }

   free (*list);
   *list = NULL;

TERMINATE:

   return error;
} /* End of ORCSeqList_Free */

/* Copy an array to the list with count */
   int
ORCSeqList_Copy (ORCSeqList *list, const int *arr, int count)
{
   int i;
   int error = 0;

   if ( NULL == list || NULL == arr) {
      error = ORCERR_NULL_POINTER;
      goto TERMINATE;
   }

   for (i = 0; i < count; ++i) {
      error = ORCSeqList_Insert(list, list->length, arr[i]);
      if ( error != 0 )  goto TERMINATE;
   }

TERMINATE:

   return error;
} /* End of ORCSeqList_Copy*/

/* Merge two lists */
   int
ORCSeqList_Merge (ORCSeqList *des, const ORCSeqList* src)
{
   int i;
   int error = 0;
   int index = -1;

   if ( NULL == des || NULL == src) {
      error = ORCERR_NULL_POINTER;
      goto TERMINATE;
   }

   for (i = 0; i < src->length ; ++i) {
      error = ORCSeqList_Insert(des, des->length, src->elem_p[i]);
      if ( error != 0 )  goto TERMINATE;
   }

   error = ORCSeqList_Sort (des, des->length, 0);
   if ( error )  goto TERMINATE;

TERMINATE:

   return error;
} /* End of ORCSeqList_Merge*/

/* Clear the whole list*/
   int
ORCSeqList_Clear (ORCSeqList *list)
{
   int error = 0;
   int temp = 0;

   while (list->length != 0) {
      error = ORCSeqList_Delete(list, 0, &temp);
      if ( error != 0 )  goto TERMINATE;
   }

TERMINATE:

   return error;
} /* End of ORCSeqList_Clear*/

/* Insert an elem to the list with index*/
   int
ORCSeqList_Insert (ORCSeqList *list,
      int index,
      const int elem)
{
   int error = 0;

   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0            ||
         index > list->length   ) {
      error = ORCERR_NOTVALID_INDEX;
      goto TERMINATE;
   }

   assert (list->elem_p != NULL);
   //extend capacity if length >= capacity in realloc
   if ( list-> length == list->capacity) {
      list->elem_p =
         (int*) realloc (list->elem_p,
               sizeof (int) * (list->capacity + ORC_LISTINCREMENT));
      if ( list->elem_p == NULL ) {
         error = ORCERR_NO_MEMORY;
         goto TERMINATE;
      }
      list->capacity += ORC_LISTINCREMENT;
   }

   //move elements which is after list[index] to next
   p = &(list->elem_p[index]);
   for (q = &(list->elem_p[list->length - 1]); q >= p; --q) {
      *(q+1) = *q;
   }

   //insert elem and increase the length of list
   *p = elem;
   ++list->length;

TERMINATE:

   return error;
} /* END of ORCSeqList_Insert */

/* Delete an element in index, and save the deleted element to *e*/
   int
ORCSeqList_Delete (ORCSeqList *list,
      int index,
      int *e)
{
   int error = 0;

   int *p = NULL;
   int *q = NULL;

   //check index
   if ( index < 0              ||
         index > list->length - 1   ) {
      error = ORCERR_NOTVALID_INDEX;
      goto TERMINATE;
   }

   //keep the deleted element
   *e = list->elem_p[index];

   //move the element which after list[index] to previous
   p = &list->elem_p[index];
   for (q = p; q <= &(list->elem_p[list->length-1]); ++q) {
      *q = *(q+1);
   }
   --list->length;

TERMINATE:

   return error;
} /* End of ORCSeqList_Delete */

/* Delete the repeat element in list */
   int
ORCSeqList_DeleteR(ORCSeqList *list)
{
   int error = 0;
   int i, index, e;

   for (i = list->length; i > 0; --i) {
      error = ORCSeqList_Find(list, i-1, list->elem_p[i-1], &index, 0);
      if ( error != 0 )  goto TERMINATE;

      if ( index != -1 ) {
         error = ORCSeqList_Delete (list, index, &e);
         if ( error != 0 )  goto TERMINATE;
      }
   }

TERMINATE:

   return error;

} /* End of ORCSeqList_DeleteR */

/* Output the list */
   int
ORCSeqList_Output (ORCSeqList *list)
{
   int i;
   int error = 0;

   if ( NULL == list ) {
      error = ORCERR_NULL_POINTER;
      goto TERMINATE;
   }

   printf ("list->length = %d\n", list->length);
   printf ("list->capacity = %d\n", list->capacity);

   if ( list->length != 0 ) {
      printf ("elements:\n");
      for (i = 0; i < list->length; ++i) {
         printf ("%d ", list->elem_p[i]);
      }
   }
   else {
      printf("This is a NULL list!");
   }
   printf ("\n\n");

TERMINATE:

   return error;
} /* End of ORCSeqList_Output */

/* Sort list by customize algorithm, bubble sort by default */
   int
ORCSeqList_Sort (ORCSeqList *list,
      int length,
      int alg)
{
   int error = 0;

   if ( NULL == list ) {
      error = ORCERR_NULL_POINTER;
      goto TERMINATE;
   }

   if (length > list->length) {
      length = list->length;
   }

   // take ORCBubble_Sort as default alg
   if ( alg == ORC_ALG_SORT_SELECT) {
      ORCSelect_Sort(list->elem_p, length);
   }
   else if ( ORC_ALG_SORT_BUBBLE ) {
      ORCBubble_Sort(list->elem_p, list->length);
   }
   else {
      ORCBubble_Sort(list->elem_p, list->length);
   }

TERMINATE:

   return error;
}

/* Find element in list by customize algorithm, Origin Find by default */
   int
ORCSeqList_Find (ORCSeqList *list,
      int length,
      const int elem,
      int *index,
      int alg)
{
   int error = 0;

   if ( NULL == list ) {
      error = ORCERR_NULL_POINTER;
      goto TERMINATE;
   }

   *index = -1;

   if (length > list->length) {
      length = list->length;
   }

   // take ORCOrigin_Find as default alg
   if ( ORC_ALG_ORIGIN_FIND == alg ) {
      ORCOrigin_Find (list->elem_p, length, elem, index);
   }
   /*else if () {
     }*/
   else {
      ORCOrigin_Find (list->elem_p, length, elem, index);
   }

TERMINATE:

   return error;
} /* End of ORCSeqList_Find */
