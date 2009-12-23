#include "linkedlist.h"
int test_one_element(void)
{
    int i;
    int error = 0;

    // Use pointer of list object use the _init function and _free function to
    // manage memory
    CLinkedList *mylist = NULL;
    error = CLinkedList_Init (&mylist);
    if ( error )  goto TERMINATE;

    printf ("mylist = %p, mylist->first = %p, mylist->last = %p\n", 
        mylist, mylist->first, mylist->last);

    // append 1 elements 
    error = CLinkedList_Append (mylist, "a");
    if ( error )  goto TERMINATE;

    error = CLinkedList_Output (mylist, ":");

    // pop like stack
    error  = CLinkedList_Pop (mylist, C_STACK);
    if ( error )  goto TERMINATE;
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // append 1 elements 
    error = CLinkedList_Append (mylist, "b");
    if ( error )  goto TERMINATE;

    error = CLinkedList_Output (mylist, ":");

    // pop like queue
    error  = CLinkedList_Pop (mylist, C_QUEUE);
    if ( error )  goto TERMINATE;
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    error = CLinkedList_Clear (mylist);
    if ( error )  goto TERMINATE;
    if ( NULL != mylist )  printf ("list is not NULL after calling clear function!\n\n");

    // append 10 elements again 
    for (i = 0; i < 10; ++i) {
        error = CLinkedList_Append (mylist, "a");
        if ( error )  goto TERMINATE;
    }

    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    error = CLinkedList_Free (&mylist);
    if ( error )  goto TERMINATE;

    if ( NULL == mylist )  printf ("list is NULL after calling free list function!\n\n");

TERMINATE:

    if ( mylist )  CLinkedList_Free (&mylist);
    return error;
}

int main(void)
{
    int i;
    int error = 0;

    error = test_one_element();
    if ( error )  goto TERMINATE;

TERMINATE:
    if ( error ) {
        int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

        for (i = 0; i < nErrors; ++i) {
            if ( errorMap[i].error == error ) {
                printf ("Cui Error: %s\n", errorMap[i].str);
            }
        }
    }

    return 0;
}
