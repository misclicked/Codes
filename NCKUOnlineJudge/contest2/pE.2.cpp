#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000009;

int dp[3][1001];
int a, b, c, k, N, i, j, ans;

int main()
{
    scanf("%d%d", &N, &k);
    dp[0][0] = dp[1][1] = dp[2][1] = 1;
    a = 0;
    b = 1;
    c = 2;
    for (i = 2; i <= N; i++)
    {
        for (j = 2; j <= min(i, k); j++)
        {
            dp[c][j] = (dp[b][j - 1] + dp[a][j - 1]);
            if (dp[c][j] > MOD)dp[c][j] -= MOD;
        }
        dp[a][0] = 0;
        dp[a][1] = dp[c][0];
        swap(a, c);
        swap(b, a);
    }
    ans = 0;
    N %= 3;
    for (i = 0; i <= k; i++)
    {
        ans = (ans + dp[N][i]);
        if (ans > MOD)ans -= MOD;
    }
    printf("%d", ans);
}