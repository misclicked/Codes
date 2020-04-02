#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define MAXN 100005
#define P 998244353
#define L 1048576
#define real double
#define eps 1e-9
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

int n, m, i, a, b, c;
int ans[MAXN << 2], add[MAXN << 2], inp[MAXN << 2];

inline int ls(const int &p)
{
    return p << 1;
}

inline int rs(const int &p)
{
    return p << 1 | 1;
}

inline int Max(const int &x, const int &y)
{
    return x > y ? x : y;
}

inline void push_up(const int &p, const int &tag)
{
    ans[p] = Max(ans[ls(p)], ans[rs(p)]) + tag;
}

void build(const int l = 1, const int r = n, const int p = 1)
{
    if (l == r)
    {
        get(ans[p]);
        inp[l] = ans[p];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls(p));
    build(mid + 1, r, rs(p));
    push_up(p, 0);
}

inline void update(const int &x, const int &y, const int &k, const int &l = 1, const int &r = n, const int &p = 1)
{
    if (l >= x && r <= y)
    {
        add[p] += k;
        ans[p] += k;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        update(x, y, k, l, mid, ls(p));
    }
    if (y > mid)
    {
        update(x, y, k, mid + 1, r, rs(p));
    }
    push_up(p, add[p]);
}

inline int query(const int &x, const int &y, const int &tag = 0, const int &l = 1, const int &r = n, const int &p = 1)
{
    if (l >= x && r <= y)
    {
        return ans[p] + tag;
    }
    int mx = -1;
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        mx = Max(mx, query(x, y, tag + add[p], l, mid, ls(p)));
    }
    if (y > mid)
    {
        mx = Max(mx, query(x, y, tag + add[p], mid + 1, r, rs(p)));
    }
    return mx;
}

int main()
{
    get(n);
    get(m);
    build();
    for (i = 0; i < m; i++)
    {
        get(a);
        get(b);
        get(c);
        if (a & 1)
        {
            update(b, b, c - inp[b]);
            inp[b] = c;
        }
        else
        {
            out(query(b, c));
            pc('\n');
        }
    }
    write(STDOUT_FILENO, _buf1, S1 - _buf1);
    return 0;
}