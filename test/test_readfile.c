#include "linkedlist.h"

int main(void)
{
    int i;
    int error = 0;
    FILE *fp;
    char line[256];
    CLinkedList *mylist1 = NULL;
    CLinkedList *mylist2 = NULL;

    fp = fopen ("..\\src\\linkedlist.c", "r");
    if ( fp == NULL)  {
        printf ("Cui Error: fopen error!\n");
        goto TERMINATE;
    }
    error = CLinkedList_Init (&mylist1);
    if ( error )  goto TERMINATE;
    error = CLinkedList_Init (&mylist2);
    if ( error )  goto TERMINATE;


    while (fgets (line, 256, fp) != NULL) {
        error = CLinkedList_Append (mylist1, line); 
        if ( error )  goto TERMINATE;
        if ( strstr (line, "malloc") != NULL) {
            error = CLinkedList_Append (mylist2, line); 
            if ( error )  goto TERMINATE;
        }
    }

    CLinkedList_Output (mylist1, NULL); 
    CLinkedList_Output (mylist2, NULL); 
    CLinkedList_Free (&mylist1);
    CLinkedList_Free (&mylist2);
    fclose (fp);

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
