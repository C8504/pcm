#include "PCM.h"

void
PCMversion(char* version)
{
    assert(version);

    sprintf(version, "PCM version: %s", VER);

} /* End of PCMversion */

void
PCMcheckerror (int error)
{
    int i = 0;

    if ( error > PCMERRSTART &&
            error < PCMERREND     )
    {
        int nErrors = sizeof (errorMap) / sizeof (errorMap[0]);

        for (i = 0; i < nErrors; ++i)
        {
            if ( errorMap[i].error == error )
            {
                printf ("PCM Error: %s\n", errorMap[i].str);
            }
        }
    }
    else if ( error != 0 )
    {
        /*       printf ("errno = %d, PCM Error(by system function calling): %s\n",  */
        /*             error, strerror (error)); */
        perror("PCM Error(by system function calling) ");
    }

} /* End of PCMcheckerror*/

void
PCMswapchar (char* arr,
             int i,
             int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int
PCMcompare (const void *x,
            const void *y)
{
    const int *a = (const int*)x;
    const int *b = (const int*)y;

    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

void**
PCMdarraynew (size_t row, size_t col, size_t size)
{
    void **arr;

    arr = malloc (sizeof(*arr) * row + size * row * col);

    if ( arr != NULL )
    {
        void *head;

        head = (void *) arr + sizeof(*arr) * row;
        memset (arr, 0, sizeof(*arr) * row + size * row * col);

        while (row--)
        {
            arr[row] = head + size * row * col;
        }
    }

    return arr;
} /* End of PCMdarraynew*/

void
PCMdarrayfree (void **arr)
{
    free (arr);
} /* End of PCMdarrayfree*/

