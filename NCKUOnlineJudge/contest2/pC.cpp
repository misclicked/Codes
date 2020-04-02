#include "lib0020.h"

long long height_limit(long long M) {
    long long l = 0, mid;
    while (l <= M) {
        mid = (l + M) / 3;
        if (is_broken(mid))M = mid - 1;
        else l = mid + 1;
    }
    return l - 1;
}