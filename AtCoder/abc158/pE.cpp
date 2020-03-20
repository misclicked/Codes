//
// Created by misclicked on 3/7/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
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
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll ans = 0;
    if (p == 2 || p == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % p == 0)
                ans += i + 1;
        }
    } else {
        unordered_map<ll, ll> mape;
        mape[0]++;
        ll now = 0, p10 = 1;
        for (int i = n - 1; ~i; i--) {
            now = (now + (s[i] - '0') * p10) % p;
            ans += mape[now];
            mape[now]++;
            p10 = (p10 * 10) % p;
        }
    }
    cout << ans << endl;
}