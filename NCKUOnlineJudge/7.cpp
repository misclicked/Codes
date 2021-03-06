#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define P 998244353
#define L 1048576
#define real double
#define eps 1e-9
#define MAXN 500005
char _buf[L], *S, *T, _buf1[L], *S1 = _buf1;

inline char gc()
{
    if (S == T)
    {
        T = (S = _buf) + fread(_buf, 1, L, stdin);
        if (S == T)return 0;
    }
    return *S++;
}

void get(int &x)
{
    char c;
    for (c = gc(); (c < '0' || c > '9') && c != '-'; c = gc());
    bool b = 0;
    if (c == '-')
    {
        b = 1;
        c = gc();
    }
    for (x = c ^ '0', c = gc(); c >= '0' && c <= '9'; c = gc())x = (x << 3) + (x << 1) + (c ^ '0');
    if (b)x = -x;
}

inline void pc(char c)
{
    if (S1 == _buf1 + L)
    {
        fwrite(_buf1, 1, L, stdout);
        S1 = _buf1;
    }
    *S1++ = c;
}

void out(int x)
{
    if (x > 9)out(x / 10);
    pc(x % 10 ^ '0');
}

int Pow(int x, int y)
{
    int s = 1;
    for (; y; y >>= 1, x = (ll) x * x % P)if (y & 1)s = (ll) s * x % P;
    return s;
}

int A(int x)
{
    return x < 0 ? -x : x;
}

int n, i, d, a[MAXN];

int main()
{
    get(n);
    if (n == 0)return 0;
    for (i = 1; i <= n; i++)
    {
        get(d);
        a[n - d] = i;
    }
    out(a[0]);
    for (i = 1; i < n; i++)
    {
        pc(' ');
        out(a[i]);
    }
    fwrite(_buf1, 1, S1 - _buf1, stdout);
    return 0;
}