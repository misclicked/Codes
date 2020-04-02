#prag\
ma GCC optimize("O3")

#include<cstdio>
#include<cstring>

#define re register int
#define fp(i, a, b) for(re i=a,I=b;i<=I;++i)
#define fd(i, a, b) for(re i=a,I=b;i>=I;--i)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
char ss[1 << 17], *A = ss, *B = ss;

inline char gc()
{
    if (A == B)
    {
        B = (A = ss) + fread(ss, 1, 1 << 17, stdin);
        if (A == B)return EOF;
    }
    return *A++;
}

template<class T>
inline void sdf(T &x)
{
    char c;
    re y = 1;
    while (c = gc(), c < 48 || 57 < c)if (c == '-')y = -1;
    x = c ^ 48;
    while (c = gc(), 47 < c && c < 58)x = (x << 1) + (x << 3) + (c ^ 48);
    x *= y;
}

char sr[1 << 25], z[20];
int C = -1, Z;

template<class T>
inline void wer(T x)
{
    re y = 0;
    if (x < 0)y = 1, x = -x;
    while (z[++Z] = x % 10 + '0', x /= 10);
    if (y)z[++Z] = '-';
    while (sr[++C] = z[Z], --Z);
    sr[++C] = ' ';
}

const int N = 1e5 + 5, M = 3e5 + 5;
typedef int arr[N];
struct edges
{
    int nx, to, w;
} e[M << 1];
int n, m, tot;
arr fi;
long long dis[N] = {0};

inline void add(re u, re v, re w)
{
    e[++tot] = (edges) {fi[u], v, w};
    fi[u] = tot;
}

namespace zkw
{
    int tr[N << 2], sgt = 1;

    inline void build(re n)
    {
        while (sgt <= n)sgt <<= 1;
        --sgt;
        tr[0] = N - 1;
    }

    inline void clr()
    { fp(i, 1, (sgt << 1) + 1)tr[i] = 0; }

    inline int cmp(const re &a, const re &b)
    { return dis[a] < dis[b] ? a : b; }

    inline void Mdy(re x, long long w)
    {
        for (re i = x + sgt; dis[tr[i]] > w; i >>= 1)tr[i] = x;
        dis[x] = w;
    }

    inline void del(re x)
    {
        tr[x += sgt] = 0;
        x >>= 1;
        while (x)tr[x] = cmp(tr[x << 1], tr[x << 1 | 1]), x >>= 1;
    }
}
using namespace zkw;

inline void dij(re s)
{
    for (int g = 0; g < n + 2; g++)dis[g] = 1000000000000005ll;
    clr();
    Mdy(s, 0);
    fp(T, 1, n)
    {
        re u = tr[1];
        del(u);
        for (re i = fi[u], v; i; i = e[i].nx)
            if (dis[v = e[i].to] > dis[u] + e[i].w)
                Mdy(v, dis[u] + e[i].w);
    }
}

int main()
{
    tot = 0;
    sdf(n);
    sdf(m);
    build(n);
    re u, v, w;
    fp(i, 1, m)sdf(u), sdf(v), sdf(w), u++, v++, add(u, v, w), add(v, u, w);
    dij(1);
    fp(i, 1, n)wer(dis[i]);
    fwrite(sr, 1, C + 1, stdout);
    return 0;
}