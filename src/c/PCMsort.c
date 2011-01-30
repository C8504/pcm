#include "PCMsort.h"
int PCMinsertsort(int *a,
                  int len)
{
    DERROR;
    int i, j;
    int t;

    assert(a != NULL);

    /* implement insert sort*/
    for (i = 1; i < len; ++i)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && t < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }

    RETURN;
} /* END of PCMinsertsort*/

int
PCMselectsort(int *a,
              int len)
{
    DERROR;
    int i, j, min;
    int t;

    assert(a != NULL);

    for (i = 0; i < len; ++i)
    {
        min = i;
        for (j = i + 1; j < len; ++j)
        {
            if ( a[j] < a[min] )
            {
                min = j;
            }
        }

        if ( i != min )
        {
            t      = a[i];
            a[i]   = a[min];
            a[min] = t;
        }
    }

    RETURN;
} /* End of PCMselectsort*/

int
PCMbubblesort(int *a,
              int len)
{
    DERROR;
    int i, j;
    int t;

    assert(a != NULL);

    for (i = 0; i < len; ++i)
    {
        for (j = i + 1; j < len; ++j)
        {
            if ( a[j] < a[i] )
            {
                t    = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    RETURN;
} /* End of PCMbubblesort*/

int
PCMshellsort(int *a,
             int len)
{
    DERROR;
    int i, j, gap;
    int temp;

    assert(a != NULL);

    while (gap * 3 + 1 <= len)
    {
        gap=gap * 3 + 1;
    }
    while (gap > 0)
    {
        for ( i = gap; i < len; i++ )
        {
            j = i - gap;
            temp = a[i];
            while (( j >= 0 ) && ( a[j] > temp ))
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
        gap = ( gap - 1 ) /3;
    }

    RETURN;
} /* End of PCMshellsort */

