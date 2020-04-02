#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")

#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;
#define L 154857
char _buf[100], buf[L], *S, *S1;

void get(long long int &x)
{
    char c;
    for (c = *S++; (c < '0' || c > '9') && c != '-'; c = *S++);
    bool b = 0;
    if (c == '-')
    {
        b = 1;
        c = *S++;
    }
    for (x = c ^ '0', c = *S++; c >= '0' && c <= '9'; c = *S++)x = (x << 3) + (x << 1) + (c ^ '0');
    if (b)x = -x;
}


long long int n, a, d, k, i, j, len;

int main()
{
    read(STDIN_FILENO, _buf, 50);
    S = _buf;
    S1 = buf;
    get(a);
    get(n);
    get(d);
    get(k);
    len = 0;
    for (; n--; a += d, d += k)
        advance(S1, sprintf(S1, "%lld ", a));
    write(STDOUT_FILENO, buf, S1 - buf);
}