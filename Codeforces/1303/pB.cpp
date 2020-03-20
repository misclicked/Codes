//
// Created by misclicked on 3/5/20.
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
        ll n, g, b;
        cin >> n >> g >> b;
        ll gd = ceil(n / 2.0);
        ll day = (gd / g - 1);
        ll ptgd = day * g + gd % g;
        cout << ptgd << endl;
        if (gd % g == 0) {
            ptgd += g;
            day++;
        }
        ll ptbd = day * b;
        ll remain = max(0ll, n - gd - ptbd);
        cout << ptgd + remain << endl;
    }
}