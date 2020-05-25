//
// Created by misclicked on 2020/4/21.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
int dp[500005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin >> T;
    vector<ll> vec;
    unordered_map<ll, int> mp;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vec.resize(n);
        for (auto &it:vec) {
            cin >> it;
        }
        mp.clear();
        for (int i = 2; i <= 2 * k; i++) {
            dp[i] = 0;
        }
        for (int i = 0; i < n / 2; i++) {
            ll now = vec[i] + vec[n - i - 1];
            dp[min(vec[i], vec[n - i - 1]) + 1]--;
            dp[max(vec[i], vec[n - i - 1]) + k + 1]++;
            mp[now]++;
        }
        ll ans = n / 2, now = n;
        for (int i = 2; i <= 2 * k; i++) {
            now += dp[i];
            //cout << dp[i] << " ";
            ans = min(ans, now - mp[i]);
        }
        //cout << endl;
        cout << ans << endl;
    }
}