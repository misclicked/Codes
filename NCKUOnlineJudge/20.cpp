#include "lib0020.h"

long long l = 0, mid;

inline long long height_limit(long long M)
{
    while (l <= M)
    {
        mid = (l + M) >> 1;
        if (is_broken(mid))M = mid - 1;
        else l = mid + 1;
    }
    return l - 1;
}