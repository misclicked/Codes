//
// Created by misclicked on 2020/4/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll dp[200005][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll T, n, a, b;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 2; j++)
                dp[i][j] = 0;
        dp[0][0] = b;
        dp[0][1] = LLONG_MAX / 2;
        string s;
        cin >> s;
        s = s;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0' && s[i - 1] == '0') {
                dp[i][0] = min(dp[i - 1][0] + a, dp[i - 1][1] + 2 * a) + b;
                dp[i][1] = min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a) + b * 2;
            } else {
                dp[i][0] = LLONG_MAX / 2;
                dp[i][1] = min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a) + b * 2;
            }
            //cout << s[i] << " " << i << " " << dp[i][0] << " " << dp[i][1] << endl;
        }
        cout << min(dp[n - 1][0] + a, dp[n - 1][1] + 2 * a) + b << endl;
    }
}