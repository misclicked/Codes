#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fsection-anchors")

#include "lib0020.h"


inline long long height_limit(long long M)
{
    register long long l = 0, mid;
    for (; l <= M;)
    {
        mid = (l + M) >> 1;
        if (is_broken(mid))M = mid - 1;
        else l = mid + 1;
    }
    return l - 1;
}