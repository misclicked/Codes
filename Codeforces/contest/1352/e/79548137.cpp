//
// Created by misclicked on 2020/5/9.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll dp[9999];
ll mp[9999];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll t;
    cin >> t;
    while (t--) {
        ll d, n;
        cin >> n;
        memset(mp, 0, sizeof(mp));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> d;
            dp[i + 1] = dp[i] + d;
            mp[d]++;
        }
        ll ans = 0;
        for (ll i = 0; i < n + 1; i++) {
            for (ll j = i + 2; j < n + 1; j++) {
                //assert((dp[j] - dp[i]) >= 0);
                if (((dp[j] - dp[i]) <= n) && mp[dp[j] - dp[i]]) {
                    ans += mp[dp[j] - dp[i]];
                    mp[dp[j] - dp[i]] = 0;
                }
            }
        }
        cout << ans << endl;
    }
}