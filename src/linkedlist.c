/* linked list by John Cui*/ 
#include "linkedlist.h"

void
ORCNode_Free (ORCLinkedNode **node)
{
    if ( *node != NULL) {
        if ( (*node)->elem != NULL) {
            free ((*node)->elem);
            (*node)->elem = NULL;
        }
        free (*node);
        *node = NULL;
    }
} /* End of ORCNode_Free */

int 
ORCNode_Alloc_and_Init (ORCLinkedNode **node, 
                      const char* elem)
{
    int error = 0;

    *node = malloc (sizeof **node);
    if ( NULL == *node ) {
        error = ORCERR_NO_MEMORY;
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

            error = ORCERR_NO_MEMORY; 
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
ORCLinkedList_Init (ORCLinkedList **list)
{
    int error = 0;

    *list = malloc (sizeof **list);
    if ( NULL == *list ) {
        error = ORCERR_NO_MEMORY;
        goto TERMINATE;
    }

    (*list)->first = NULL;
    (*list)->last  = NULL;

TERMINATE:

    return error;
} /* End of ORCLinkedList_Init */


/* Free the list*/
int
ORCLinkedList_Free (ORCLinkedList **list)
{
    int error = 0;
    ORCLinkedNode *oldp = NULL;

    while ( (*list)->first != NULL ) {
        oldp = (*list)->first;
        (*list)->first = (*list)->first->next;
        ORCNode_Free (&oldp);
    }
    (*list)->first = (*list)->last = NULL;
    free (*list);
    *list = NULL;

    return error;
} /* End of ORCLinkedList_Free */

int 
ORCLinkedList_Append (ORCLinkedList *list, 
                    const char* elem)
{
    ORCLinkedNode *new_node = NULL; 

    int error = ORCNode_Alloc_and_Init (&new_node, elem); 
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
} /* END of ORCLinkedList_Append */

//insert the new_node after "p"
int
ORCLinkedList_Insert (ORCLinkedList *list,
                    int         pos,
                    const char* elem)
{
    int error;
    int j = 0;
    int len = ORCLinkedList_Length(list);
    ORCLinkedNode *p = list->first;
    ORCLinkedNode *new_node = NULL; 

    // If list is an empty list, then ignore pos
    // and the new_node is the list->first and list->last
    if ( len == 0 ) {
        error = ORCNode_Alloc_and_Init (&new_node, elem); 
        if ( error )  goto TERMINATE; 
        list->first = list->last = new_node;
    }
    else {
        // if pos == len, then just append it
        if ( pos == len ) {
            error = ORCLinkedList_Append (list, elem);
            if ( error )  goto TERMINATE;
        }
        // if pos in the middle of list
        else {
            // check pos
            if ( pos < 1  || 
                pos > len  ) {
                    error = ORCERR_NOTVALID_INDEX;
                    goto TERMINATE;
            }

            // find the node at pos "p"
            while (p && j < pos-1) {
                p = p->next;
                ++j;
            }

            // creat new_node
            error = ORCNode_Alloc_and_Init (&new_node, elem); 
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
ORCLinkedList_Output (ORCLinkedList *list, 
                    const char* sp)
{
    int error = 0;

    ORCLinkedNode *p;

    if ( list == NULL ) {
        error = ORCERR_NULL_POINTER;
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
            printf ("Have %d elements in this list\n\n", ORCLinkedList_Length (list));
    }
    else {
        printf ("This is an empty list now\n\n");
    }

TERMINATE:

    return error;
} /* End of ORCLinkedList_Output */

int
ORCLinkedList_Clear (ORCLinkedList *list)
{
    int error = 0;

    while (0 != ORCLinkedList_Length (list)) {
        error = ORCLinkedList_Pop (list, ORC_STACK);
        if ( error )  goto TERMINATE;
    }

TERMINATE:

    return error;
} /* End of ORCLinkedList_Clear */

// Pop is a method used in both stack and queue with flag
int 
ORCLinkedList_Pop (ORCLinkedList *list, 
                 int flag)
{
    int error = 0;
    ORCLinkedNode *p = NULL;

    if ( flag == ORC_STACK ) {
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
            error = ORCERR_EMPTY_LIST;
            goto TERMINATE;
        }
    }
    else if ( flag == ORC_QUEUE ) {
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
            error = ORCERR_EMPTY_LIST;
            goto TERMINATE;
        }
    }
    else {
        error = ORCERR_NOT_STACK_AND_QUEUE;
        goto TERMINATE;
    }

    free (p->elem);
    free (p);

TERMINATE:

    return error;
} /* End of ORCLinkedList_Pop */
int
ORCLinkedList_Length(ORCLinkedList *list)
{
    int length = 0;
    ORCLinkedNode *p = list->first;

    while ( p != NULL) {
        ++length;
        p = p->next;
    }

    return length;
} /* END of ORCLinkedList_Length */
