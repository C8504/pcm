#include "seqlist.h"

int main(void)
{
    int i;
    int error = 0;

    ORCSeqList* mylist = NULL;

    printf ("Init my list\n");
    error = ORCSeqList_Init (&mylist);
    if ( error )  goto TERMINATE;

    printf ("Insert 1-3 elements");

    for (i = 0; i < 3; ++i) {
        error = ORCSeqList_Insert (mylist, i, i);
        if ( error )  goto TERMINATE;
    }
    error = ORCSeqList_Output(mylist);
    if ( error )  goto TERMINATE;

    printf ("Insert 3-5 elements");
    for (i = 3; i < C_LIST_INIT_SIZE ; ++i) {
        error = ORCSeqList_Insert (mylist, i, i);
        if ( error )  goto TERMINATE;
    }
    error = ORCSeqList_Output(mylist);
    if ( error )  goto TERMINATE;

    printf ("Insert 5-10 elements");
    for (i = 5; i < 10; ++i) {
        error = ORCSeqList_Insert (mylist, i, i);
        if ( error )  goto TERMINATE;
    }
    error = ORCSeqList_Output(mylist);
    if ( error )  goto TERMINATE;

    printf ("Free my list\n");
    error = ORCSeqList_Free (&mylist);
    if ( error )  goto TERMINATE;

    if ( mylist == NULL )  printf("Free mylist successfully!");
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
