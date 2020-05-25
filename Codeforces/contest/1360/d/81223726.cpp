//
// Created by misclicked on 2020/5/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifndef OUO
#define cerr if (false) cerr
#endif

int main() {
#ifdef OUO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 1;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0 && i <= k) {
                ans = max(i, ans);
            }
            if (n % i == 0 && (n / i) <= k) {
                ans = max((n / i), ans);
            }
        }
        cout << n / ans << endl;
    }
}