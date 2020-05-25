//
// Created by misclicked on 2020/4/13.
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
    ll T;
    cin >> T;
    unordered_map<ll, ll> mp;
    vector<ll> sz;
    while (T--) {
        ll n, d;
        cin >> n;
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> d;
            mp[d]++;
        }
        ll dis = 0;
        sz.clear();
        for (auto it:mp) {
            sz.push_back(it.second);
        }
        sort(sz.begin(), sz.end(), greater<ll>());
        ll ans = min(sz[0], (ll) sz.size() - 1);
        if (sz[0] > 1) {
            ans = max(ans, min(sz[0] - 1, (ll) sz.size()));
        }
        if (n == 1)
            cout << "0" << endl;
        else
            cout << ans << endl;

    }
}