#include "linkedlist.h"
int test_many_elements()
{
    int i;
    int error = 0;
    ORCLinkedList* mylist = NULL;

    error = ORCLinkedList_Init (&mylist);
    if ( error )  goto TERMINATE;

    // insert  elements here
    error = ORCLinkedList_Insert (mylist, 0, "1");
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Insert (mylist, 1, "2");
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Insert (mylist, ORCLinkedList_Length(mylist), "end");
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // append 10 elements 
    for (i = 0; i < 10; ++i) {
        error = ORCLinkedList_Append (mylist, "a");
        if ( error )  goto TERMINATE;
    }

    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // append 10 elements too
    for (i = 0; i < 10; ++i) {
        error = ORCLinkedList_Append (mylist, "b");
        if ( error )  goto TERMINATE;
    }
    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // insert  elements here
    error = ORCLinkedList_Insert (mylist, 1, "3");
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Insert (mylist, 2, "4");
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Insert (mylist, ORCLinkedList_Length(mylist), "end");
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // pop like stack
    for (i = 0; i < 5; ++i) {
        error  = ORCLinkedList_Pop (mylist, ORC_STACK);
        if ( error )  goto TERMINATE;
    }
    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // pop like queue
    for (i = 0; i < 5; ++i) {
        error  = ORCLinkedList_Pop (mylist, ORC_QUEUE);
        if ( error )  goto TERMINATE;

    }
    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // pop like stack
    for (i = 0; i < 10; ++i) {
        error  = ORCLinkedList_Pop (mylist, ORC_STACK);
        if ( error )  goto TERMINATE;
    }
    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    // insert 10 elements again 
    for (i = 0; i < 10; ++i) {
        error = ORCLinkedList_Append (mylist, "a");
        if ( error )  goto TERMINATE;
    }

    error = ORCLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    error = ORCLinkedList_Free (&mylist);
    if ( error )  goto TERMINATE;

    if ( NULL == mylist )  printf ("free list successfully!\n\n");

TERMINATE:

    if ( mylist )  ORCLinkedList_Free (&mylist);
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
                printf ("ORC Error: %s\n", errorMap[i].str);
            }
        }
    }

    return 0;
}
