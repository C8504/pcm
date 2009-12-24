#include "seqlist.h"

int main(void)
{
    int i;
    int error = 0;

    int a[5] = {1, 3, 3, 7, 7};
    int b[5] = {1, 3, 6, 6, 10};
    
    ORCSList odd = NULL;
    ORCSList even = NULL;

    error = ORCSeqList_Init (&odd);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Init (&even);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Copy (odd, a, 5);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Copy (even, b, 5);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Merge (odd, even);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_DeleteR (odd);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Output (odd);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Output (even);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Free (&odd);
    if ( error )  goto TERMINATE;

    error = ORCSeqList_Free (&even);
    if ( error )  goto TERMINATE;

    if ( even == NULL )  printf ("Free even successfully!\n");
    if ( odd == NULL  )  printf ("Free odd successfully!\n");
TERMINATE:
    if ( error ) {
        int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

        for (i = 0; i < nErrors; ++i) {
            if ( errorMap[i].error == error ) {
                printf ("ORC Error: %s\n", errorMap[i].str);
            }
        }
        if ( NULL != odd  )  ORCSeqList_Free (&odd);
        if ( NULL != even )  ORCSeqList_Free (&even);
    }

    return 0;
}
