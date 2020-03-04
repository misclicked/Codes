//
// Created by misclicked on 3/3/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll dp[505][505] = {0};

ll dfs(ll L, ll R) {
    if (dp[L][R])
        return dp[L][R];
    if (R == 0)return 0;
    if (L == 0)return 1;
    ll ans = 0;
    for (int i = 1; i < R && L - i >= 0; i++) {
        ans += dfs(L - i, i);
    }
    return dp[L][R] = ans;
}

void build() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = i; j <= 500; j++) {
            for (int k = i - 1; k >= 0; k--) {
                dp[j][i] += dp[j - i][k];
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n;
    build();
    while (cin >> n) {
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[n][i];
            cerr << n << " " << i << " " << dp[n][i] << endl;
        }
        cout << ans << endl;
    }
}