//
// Created by misclicked on 3/3/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin >> n;
    int dp[200005];
    int dp2[200005];
    int inp[200005];
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    int ans = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (inp[i] > inp[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        ans = max(dp[i], ans);
        cerr << i << " " << dp[i] << endl;
    }
    dp2[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (inp[i] < inp[i + 1]) {
            dp2[i] = dp2[i + 1] + 1;
        } else {
            dp2[i] = 1;
        }
        cerr << i << " " << dp2[i] << endl;
    }
    for (int i = 1; i < n - 1; i++) {
        if (inp[i - 1] < inp[i + 1]) {
            cerr << i << " " << dp[i - 1] + dp2[i + 1] << endl;
            ans = max(ans, dp[i - 1] + dp2[i + 1]);
        }
    }
    cout << ans << endl;
}