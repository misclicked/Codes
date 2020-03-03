//
// Created by misclicked on 2/21/20.
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
    int t, n, d, a;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        ll ans = 0;
        cin >> ans;
        for (int i = 1; i < n; i++) {
            cin >> a;
            ans += min(d, a * i) / i;
            d -= min(d, a * i);
        }
        cout << ans << endl;
    }
}