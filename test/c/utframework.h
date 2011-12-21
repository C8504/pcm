#ifndef UTFRAMEWORK_INCLUDED
#define UTFRAMEWORK_INCLUDED

// unit test framework in C
typedef void (*UnitTestFunction)(void);

static void run_test(UnitTestFunction test)
{
    test();
}

void run_tests(UnitTestFunction *tests)
{
    int i = 0;

    for (i = 0; tests[i] != NULL; ++i)
    {
        run_test(tests[i]);
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>testcase: %d done!\n\n", i);
    }
}


#endif // UTFRAMEWORK_INCLUDED
