//
// Created by ISMP on 2020/3/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll ans = 0;
ll n, m;
vector<ll> vec;
ll vec[3005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    ll data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        vec.push_back(min(data, m));
    }
    for (int i = 0; i < n; i++) {
        for (ll j = 3000; j >= vec[j]; j--) {
            dp[j] = max(dp[j], dp[j - min(j, vec[i])] + min(j, vec[i]));
        }
    }
    for (ll i = 0; i < 3000; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans / 2 << endl;
}