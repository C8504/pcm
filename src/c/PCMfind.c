#include "PCMfind.h"

int
PCMoriginfind(int *a,
              int length,
              const int elem,
              int *index)
{
    DERROR;
    int i;

    assert(a != NULL);

    for (i = 0; i < length; ++i)
    {
        if ( a[i] == elem )
        {
            *index = i;
        }
    }

    RETURN;
} /* End of PCMoriginfind*/

int
PCMbinfind(int *a,
           int length,
           const int elem,
           int *index)
{
    DERROR;
    int mid = 0;
    int low = 0;
    int high = length-1;

    assert(a != NULL);

    *index = -1;
    while (low <= high)
    {
        mid = (low + high)/2;
        if ( elem > a[mid] )
        {
            low  = mid + 1;
        }
        else if( elem < a[mid] )
        {
            high = mid - 1;
        }
        else
        {
            *index = mid;
            goto TERMINATE;
        }
    }

    RETURN;
} /* End of PCMbinfind*/

