#include "PCMlinkedlist.h"
int testoneelement(void)
{
    int i;
    int error = 0;
    enum PCMPOPTYPE type;

    // Use pointer of list object use the init function and free function to
    // manage memory
    PCMlinkedlist *mylist = NULL;
    CALL(PCMlinkedlistinit (&mylist));

    printf ("mylist = %p, mylist->first = %p, mylist->last = %p\n",
            mylist, mylist->first, mylist->last);

    // append 2 elements
    CALL(PCMlinkedlistappend (mylist, "a"));
    CALL(PCMlinkedlistappend (mylist, "A"));
    CALL(PCMlinkedlistoutput (mylist, "<append>"));

    // pop like stack
    type = PCMPOPSTACK;
    CALL(PCMlinkedlistpop (mylist, type));
    CALL(PCMlinkedlistoutput (mylist, "<pop in stack>"));

    // append 1 elements
    CALL(PCMlinkedlistappend (mylist, "b"));
    CALL(PCMlinkedlistoutput (mylist, "<append>"));

    // pop like queue
    type = PCMPOPQUEUE;
    CALL(PCMlinkedlistpop (mylist, type));
    CALL(PCMlinkedlistoutput (mylist, "<pop in queue>"));

    CALL(PCMlinkedlistclear (mylist));
    if ( NULL != mylist )  printf ("list is not NULL after calling clear function!\n\n");

    // append 10 elements again
    for (i = 0; i < 10; ++i)
    {
        CALL(PCMlinkedlistappend (mylist, "a"));
    }

    CALL(PCMlinkedlistoutput (mylist, "<append>"));

    CALL(PCMlinkedlistfree (&mylist));

    if ( NULL == mylist )  printf ("list is NULL after calling free list function!\n\n");

TERMINATE:

    if ( mylist )  PCMlinkedlistfree (&mylist);
    return error;
}

int main(void)
{
    int i;
    int error = 0;

    CALL(testoneelement());

TERMINATE:
    PCMcheckerror (error);
    return 0;
}
