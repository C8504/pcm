#include "PCMlinkedlist.h"
#include "utframework.h"

void test_PCM_link_init_and_free(void)
{
    int i = 0;
    int error = 0;

    /*    PCMlinkedlist *mylist = NULL; */
    /*    PCMlinkedlist mylist; */
    /*    mylist = &l; */
    /*    PCMlinkedlist *p = &mylist; */
    PCMlinkedlist *p = NULL;
    CALL(PCMlinkedlistinit (&p));
    CALL(PCMlinkedlistoutput (p, ":"));
    CALL(PCMlinkedlistfree (&p));

TERMINATE:
    PCMcheckerror (error);

}

void test_PCM_link_many_element(void)
{
    int i;
    int error = 0;
    enum PCMPOPTYPE type;
    PCMlinkedlist* mylist = NULL;

    CALL(PCMlinkedlistinit (&mylist));

    // insert  elements here
    CALL(PCMlinkedlistinsert (mylist, 0, "1"));
    CALL(PCMlinkedlistinsert (mylist, 1, "2"));
    CALL(PCMlinkedlistinsert (mylist, PCMlinkedlistlength(mylist), "end"));
    CALL(PCMlinkedlistoutput (mylist, ":"));

    // append 10 elements
    for (i = 0; i < 10; ++i)
    {
        CALL(PCMlinkedlistappend (mylist, "a"));
    }

    CALL(PCMlinkedlistoutput (mylist, ":"));

    // append 10 elements again
    for (i = 0; i < 10; ++i)
    {
        CALL(PCMlinkedlistappend (mylist, "b"));
    }
    CALL(PCMlinkedlistoutput (mylist, ":"));

    // insert  elements here
    CALL(PCMlinkedlistinsert (mylist, 1, "3"));
    CALL(PCMlinkedlistinsert (mylist, 2, "4"));
    CALL(PCMlinkedlistinsert (mylist, PCMlinkedlistlength(mylist), "end"));
    CALL(PCMlinkedlistoutput (mylist, ":"));

    // pop like stack
    type = PCMPOPSTACK;
    for (i = 0; i < 5; ++i)
    {
        CALL(PCMlinkedlistpop (mylist, type));
    }
    CALL(PCMlinkedlistoutput (mylist, ":"));

    // pop like queue
    type = PCMPOPQUEUE;
    for (i = 0; i < 5; ++i)
    {
        CALL(PCMlinkedlistpop (mylist, type));

    }
    CALL(PCMlinkedlistoutput (mylist, ":"));

    // pop like stack
    type = PCMPOPQUEUE;
    for (i = 0; i < 10; ++i)
    {
        CALL(PCMlinkedlistpop (mylist, type));
    }
    CALL(PCMlinkedlistoutput (mylist, ":"));

    // insert 10 elements again
    for (i = 0; i < 10; ++i)
    {
        CALL(PCMlinkedlistappend (mylist, "a"));
    }

    CALL(PCMlinkedlistoutput (mylist, ":"));
    CALL(PCMlinkedlistfree (&mylist));

    if ( NULL == mylist )  printf ("free list successfully!\n\n");

TERMINATE:

    if ( mylist )  PCMlinkedlistfree (&mylist);
    PCMcheckerror (error);

}

void test_PCM_link_one_element(void)
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
    PCMcheckerror (error);

}

void test_PCM_link_readfile(void)
{
    int i;
    int error = 0;
    FILE *fp;
    char line[256];
    PCMlinkedlist *mylist1 = NULL;
    PCMlinkedlist *mylist2 = NULL;

    fp = fopen ("Makefile", "r");
    if ( fp == NULL)
    {
        printf ("PCM Error: fopen error!\n");
        goto TERMINATE;
    }
    CALL(PCMlinkedlistinit (&mylist1));
    CALL(PCMlinkedlistinit (&mylist2));


    while (fgets (line, 256, fp) != NULL)
    {
        CALL(PCMlinkedlistappend (mylist1, line));
        if ( strstr (line, "malloc") != NULL)
        {
            CALL(PCMlinkedlistappend (mylist2, line));
        }
    }

    PCMlinkedlistoutput (mylist1, NULL);
    PCMlinkedlistoutput (mylist2, NULL);
    PCMlinkedlistfree (&mylist1);
    PCMlinkedlistfree (&mylist2);
    fclose (fp);

TERMINATE:
    PCMcheckerror (error);
}

static UnitTestFunction tests[] =
{
    test_PCM_link_init_and_free,
    test_PCM_link_many_element,
    test_PCM_link_one_element,
    test_PCM_link_readfile,
    NULL
};

int main()
{
    run_tests(tests);

    return 0;
}
