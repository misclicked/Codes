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
    int t, n, x, g, a, k;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        g = 0;
        k = 1;
        while (n--) {
            cin >> a;
            g = max(a, g);
            if (a == x) {
                cout << 1 << endl;
                k = 0;
            }
        }
        if (k)
            cout << max((int) ceil((double) x / g), 2) << endl;
    }

}