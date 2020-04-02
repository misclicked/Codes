#include <iostream>

using namespace std;
#define MAXN 1000005
#define LGN 20
int st[MAXN][LGN];
int n, m;

void build()
{
    for (int h = 1; h < LGN; h++)
    {
        int len = 1 << (h - 1), i = 0;
        for (; i + len < n; i++)
            st[i][h] = max(st[i][h - 1], st[i + len][h - 1]);
        for (; i < n; i++)
            st[i][h] = st[i][h - 1];
    }
}

int query(int l, int r)
{
    int h = __lg(r - l + 1);
    int len = 1 << h;
    return max(st[l][h], st[r - len + 1][h]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)scanf("%d", &st[i][0]);
    build();
    for (int i = 0; i < n - m + 1; i++)
    {
        printf("%d ", query(i, i + m - 1));
    }
}
