//
// Created by ISMP on 2020/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int dp[100005] = {0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, m;
    cin >> n >> m;
    ll x, r;
    vector<pll> vec;
    for (int i = 0; i < n; i++) {
        cin >> x >> r;
        vec.push_back({x, r});
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for (int i = 1; i <= m;) {
        int idx = lower_bound(vec.begin(), vec.end(), pll(i, 0)) - vec.begin();
        if (idx == vec.size()) {
            ans += (m - i) + 1;
            break;
        }
        cout << i << " " << vec[idx].first << endl;
        x = vec[idx].first;
        r = vec[idx].second;
        if (x - r > i) {
            ll newr = (x - i);
            cout << "newr: " << newr << endl;
            ans += x - i - r;
            cout << "Used: " << (x - i - r) << endl;
            i = x + newr + 1;
            cout << "newi: " << i << endl;
        } else {
            i = x + r + 1;
            cout << "newi: " << i << endl;
        }
    }
    cout << ans << endl;
}