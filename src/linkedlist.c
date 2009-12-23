/* linked list by John Cui*/ 
#include "linkedlist.h"

void
CNode_Free (CLinkedNode **node)
{
    if ( *node != NULL) {
        if ( (*node)->elem != NULL) {
            free ((*node)->elem);
            (*node)->elem = NULL;
        }
        free (*node);
        *node = NULL;
    }
} /* End of CNode_Free */

int 
CNode_Alloc_and_Init (CLinkedNode **node, 
                      const char* elem)
{
    int error = 0;

    *node = malloc (sizeof **node);
    if ( NULL == *node ) {
        error = CERR_NO_MEMORY;
        goto TERMINATE;
    }

    if ( elem != NULL ) {
        size_t s_size = strlen (elem) + 1; 
        (*node)->elem = malloc (s_size); 
        //memset ((*node)->elem, '\0', s_size);
        if (NULL == (*node)->elem) {
            // free *node if alloc elem failed.
            free (*node);
            *node = NULL;

            error = CERR_NO_MEMORY; 
            goto TERMINATE;
        }
        else {
            //strncat ((*node)->elem, elem, strlen(elem));
            memcpy ((*node)->elem, elem, s_size);
        }
    }
    else {
        (*node)->elem = NULL;
    }

    (*node)->next = NULL;
    (*node)->prev = NULL;

TERMINATE:

    return error;
}
int
CLinkedList_Init (CLinkedList **list)
{
    int error = 0;

    *list = malloc (sizeof **list);
    if ( NULL == *list ) {
        error = CERR_NO_MEMORY;
        goto TERMINATE;
    }

    (*list)->first = NULL;
    (*list)->last  = NULL;

TERMINATE:

    return error;
} /* End of CLinkedList_Init */


/* Free the list*/
int
CLinkedList_Free (CLinkedList **list)
{
    int error = 0;
    CLinkedNode *oldp = NULL;

    while ( (*list)->first != NULL ) {
        oldp = (*list)->first;
        (*list)->first = (*list)->first->next;
        CNode_Free (&oldp);
    }
    (*list)->first = (*list)->last = NULL;
    free (*list);
    *list = NULL;

    return error;
} /* End of CLinkedList_Free */

int 
CLinkedList_Append (CLinkedList *list, 
                    const char* elem)
{
    CLinkedNode *new_node = NULL; 

    int error = CNode_Alloc_and_Init (&new_node, elem); 
    if ( error )  goto TERMINATE; 

    if ( list->first == NULL && 
        list->last  == NULL    ) { 
            list->last = list->first = new_node; 
    } 
    else { 
        new_node->prev = list->last; 
        list->last->next = new_node; 
        list->last = new_node; 
    } 

TERMINATE: 

    return error; 
} /* END of CLinkedList_Append */

//insert the new_node after "p"
int
CLinkedList_Insert (CLinkedList *list,
                    int         pos,
                    const char* elem)
{
    int error;
    int j = 0;
    int len = CLinkedList_Length(list);
    CLinkedNode *p = list->first;
    CLinkedNode *new_node = NULL; 

    // If list is an empty list, then ignore pos
    // and the new_node is the list->first and list->last
    if ( len == 0 ) {
        error = CNode_Alloc_and_Init (&new_node, elem); 
        if ( error )  goto TERMINATE; 
        list->first = list->last = new_node;
    }
    else {
        // if pos == len, then just append it
        if ( pos == len ) {
            error = CLinkedList_Append (list, elem);
            if ( error )  goto TERMINATE;
        }
        // if pos in the middle of list
        else {
            // check pos
            if ( pos < 1  || 
                pos > len  ) {
                    error = CERR_NOTVALID_INDEX;
                    goto TERMINATE;
            }

            // find the node at pos "p"
            while (p && j < pos-1) {
                p = p->next;
                ++j;
            }

            // creat new_node
            error = CNode_Alloc_and_Init (&new_node, elem); 
            if ( error )  goto TERMINATE; 

            // insert the new_node after "p"
            new_node->next = p->next;
            new_node->prev = p;
            p->next = new_node;
        }
    }


TERMINATE:

    return error;
}
int 
CLinkedList_Output (CLinkedList *list, 
                    const char* sp)
{
    int error = 0;

    CLinkedNode *p;

    if ( list == NULL ) {
        error = CERR_NULL_POINTER;
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
            printf ("Have %d elements in this list\n\n", CLinkedList_Length (list));
    }
    else {
        printf ("This is an empty list now\n\n");
    }

TERMINATE:

    return error;
} /* End of CLinkedList_Output */

int
CLinkedList_Clear (CLinkedList *list)
{
    int error = 0;

    while (0 != CLinkedList_Length (list)) {
        error = CLinkedList_Pop (list, C_STACK);
        if ( error )  goto TERMINATE;
    }

TERMINATE:

    return error;
} /* End of CLinkedList_Clear */

// Pop is a method used in both stack and queue with flag
int 
CLinkedList_Pop (CLinkedList *list, 
                 int flag)
{
    int error = 0;
    CLinkedNode *p = NULL;

    if ( flag == C_STACK ) {
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
            error = CERR_EMPTY_LIST;
            goto TERMINATE;
        }
    }
    else if ( flag == C_QUEUE ) {
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
            error = CERR_EMPTY_LIST;
            goto TERMINATE;
        }
    }
    else {
        error = CERR_NOT_STACK_AND_QUEUE;
        goto TERMINATE;
    }

    free (p->elem);
    free (p);

TERMINATE:

    return error;
} /* End of CLinkedList_Pop */
int
CLinkedList_Length(CLinkedList *list)
{
    int length = 0;
    CLinkedNode *p = list->first;

    while ( p != NULL) {
        ++length;
        p = p->next;
    }

    return length;
} /* END of CLinkedList_Length */
