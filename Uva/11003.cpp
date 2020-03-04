//
// Created by misclicked on 3/4/20.
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
    vector<pii> vec;
    int dp[6005];
    while (cin >> n && n) {
        vec.clear();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            vec.push_back({a, b});
        }
        reverse(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            for (int j = 6000; j >= vec[i].first; j--) {
                if (vec[i].second >= j - vec[i].first) {
                    dp[j] = max(dp[j], dp[j - vec[i].first] + 1);
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < 6000; i++) {
            ans = max(ans, (ll) dp[i]);
        }
        cout << ans << endl;
    }
}