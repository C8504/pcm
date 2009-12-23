#include "linkedlist.h"

int main(void)
{
    int i;
    int error = 0;
    FILE *fp;
    char line[256];
    ORCLinkedList *mylist1 = NULL;
    ORCLinkedList *mylist2 = NULL;

    fp = fopen ("..\\src\\linkedlist.c", "r");
    if ( fp == NULL)  {
        printf ("ORC Error: fopen error!\n");
        goto TERMINATE;
    }
    error = ORCLinkedList_Init (&mylist1);
    if ( error )  goto TERMINATE;
    error = ORCLinkedList_Init (&mylist2);
    if ( error )  goto TERMINATE;


    while (fgets (line, 256, fp) != NULL) {
        error = ORCLinkedList_Append (mylist1, line); 
        if ( error )  goto TERMINATE;
        if ( strstr (line, "malloc") != NULL) {
            error = ORCLinkedList_Append (mylist2, line); 
            if ( error )  goto TERMINATE;
        }
    }

    ORCLinkedList_Output (mylist1, NULL); 
    ORCLinkedList_Output (mylist2, NULL); 
    ORCLinkedList_Free (&mylist1);
    ORCLinkedList_Free (&mylist2);
    fclose (fp);

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
