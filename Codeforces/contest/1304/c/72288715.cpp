//
// Created by misclicked on 3/3/20.
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
    while (T--) {
        ll n, m;
        cin >> n >> m;
        ll T, L, R;
        L = R = m;
        T = 0;
        ll t, l, r;
        string s = "YES";
        while (n--) {
            cin >> t >> l >> r;
            L = L - (t - T);
            R = R + (t - T);
            cerr << T << ":" << t << endl;
            if (r < L || l > R)s = "NO";
            L = max(L, l);
            R = min(r, R);
            T = t;
            cerr << L << " " << R << endl;
        }
        cout << s << endl;
    }
}