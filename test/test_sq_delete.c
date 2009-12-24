#include "seqlist.h"

int main(void)
{
    int i, e;
    int error = 0;
    ORCSeqList* mylist = NULL;

    error = ORCSeqList_Init (&mylist);
    if ( error )  goto TERMINATE;

    printf ("Insert 3 elements\n");

    error = ORCSeqList_Insert (mylist, 0, 8);
    if ( error )  goto TERMINATE;
    error = ORCSeqList_Insert (mylist, 0, 100);
    if ( error )  goto TERMINATE;
    error = ORCSeqList_Insert (mylist, 0, 1000);
    if ( error )  goto TERMINATE;

    ORCSeqList_Output (mylist);
    
    printf ("Delete 2th element\n");
    error = ORCSeqList_Delete (mylist, 2, &e);
    if ( error )  goto TERMINATE;
    printf ("The 2th element %d was deleted\n", e);

    error = ORCSeqList_Output (mylist);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Sort (mylist, mylist->length, 0);
    if ( error )  goto TERMINATE;
    
    error = ORCSeqList_Output (mylist);
    if ( error )  goto TERMINATE;
    
    error = ORCSeqList_Clear (mylist);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Output (mylist);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Free (&mylist);
    if ( error )  goto TERMINATE;

    if ( mylist == NULL )  printf("sqlist free successfully!\n");
TERMINATE:
    if ( error ) {
        int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

        for (i = 0; i < nErrors; ++i) {
            if ( errorMap[i].error == error ) {
                printf ("ORC Error: %s\n", errorMap[i].str);
            }
        }
        if ( NULL != mylist )  ORCSeqList_Free (&mylist);
    }

    return 0;
}
