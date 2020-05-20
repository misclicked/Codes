//
// Created by ISMP on 2020/4/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

#define MOD 48763

ll dp[105][105][105] = {0};


inline ll get(int i, int j, int k) {
    if (i == 75)return 0;
    return dp[i][j][k];
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
    ll n, m;
    cin >> n >> m;
    dp[2][1][1] = 1;
    for (int i = 2; i <= 101; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                dp[i][j][k] =
                        ((get(i, j, k) + get(i, j - 1, k)) % MOD + (get(i, j, k - 1)
                                                                    + get(i - 2, j, k)) % MOD
                         + get(i - 1, j - 1, k)) % MOD;
            }
        }
    }
    //cout << get(3, 2, 2) << endl;
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= m; k++) {
            ans = (ans + get(101, j, k)) % MOD;
        }
    }
    cout << ans % MOD << endl;
}