//
// Created by misclicked on 2020/4/15.
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
    int T;
    cin >> T;
    while (T--) {
        ll x, n, m;
        cin >> x >> n >> m;
        string ans = "NO";
        while (true) {
            if (m >= ceill(x / 10.0)) {
                ans = "YES";
                break;
            }
            if (x >= 20 && n) {
                x = x / 2 + 10;
                n--;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
}