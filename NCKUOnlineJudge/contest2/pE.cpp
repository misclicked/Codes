//
// Created by ISMP on 2020/3/25.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000009ll

int dp[3333][3333];

int main() {
    int k, N;
    cin >> N >> k;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }
    dp[1][1] = 1;
    dp[2][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = k; j >= 1; j--) {
            dp[i][j] = (dp[i][j] % MOD + (dp[i - 1][j - 1] % MOD + dp[i - 2][j - 1] % MOD) % MOD) % MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }
    cout << ans << endl;
}