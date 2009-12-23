#include "linkedlist.h"

int main(void)
{
    int i = 0;
    int error = 0;

    CLinkedList *mylist = NULL;

    error = CLinkedList_Init (&mylist);
    if ( error )  goto TERMINATE;

    error = CLinkedList_Output (mylist, ":");
    if ( error )  goto TERMINATE;

    error = CLinkedList_Free (&mylist);
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
