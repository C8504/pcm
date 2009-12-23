#include "linkedlist.h"
int test_many_elements()
{
    int i;
    int error = 0;
    CLinkedList* mylist = NULL;

    error = CLinkedList_Init (&mylist);
    if ( error )  goto TERMINATE;

    // insert  elements here
    error = CLinkedList_Insert (mylist, 0, "1");
    if ( error )  goto TERMINATE;
    error = CLinkedList_Insert (mylist, 1, "2");
    if ( error )  goto TERMINATE;
    error = CLinkedList_Insert (mylist, CLinkedList_Length(mylist), "end");
    if ( error )  goto TERMINATE;
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // append 10 elements 
    for (i = 0; i < 10; ++i) {
        error = CLinkedList_Append (mylist, "a");
        if ( error )  goto TERMINATE;
    }

    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // append 10 elements too
    for (i = 0; i < 10; ++i) {
        error = CLinkedList_Append (mylist, "b");
        if ( error )  goto TERMINATE;
    }
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // insert  elements here
    error = CLinkedList_Insert (mylist, 1, "3");
    if ( error )  goto TERMINATE;
    error = CLinkedList_Insert (mylist, 2, "4");
    if ( error )  goto TERMINATE;
    error = CLinkedList_Insert (mylist, CLinkedList_Length(mylist), "end");
    if ( error )  goto TERMINATE;
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // pop like stack
    for (i = 0; i < 5; ++i) {
        error  = CLinkedList_Pop (mylist, C_STACK);
        if ( error )  goto TERMINATE;
    }
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // pop like queue
    for (i = 0; i < 5; ++i) {
        error  = CLinkedList_Pop (mylist, C_QUEUE);
        if ( error )  goto TERMINATE;

    }
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // pop like stack
    for (i = 0; i < 10; ++i) {
        error  = CLinkedList_Pop (mylist, C_STACK);
        if ( error )  goto TERMINATE;
    }
    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // insert 10 elements again 
    for (i = 0; i < 10; ++i) {
        error = CLinkedList_Append (mylist, "a");
        if ( error )  goto TERMINATE;
    }

    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    error = CLinkedList_Free (&mylist);
    if ( error )  goto TERMINATE;

    if ( NULL == mylist )  printf ("free list successfully!\n\n");

TERMINATE:

    if ( mylist )  CLinkedList_Free (&mylist);
    return error;
}

int main(void)
{
    int i;
    int error = 0;

    error = test_many_elements();
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
