//
// Created by misclicked on 3/16/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
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
    ll u, v;
    cin >> u >> v;
    ll x = (v - u) >> 1;
    if (u > v || u % 2 != v % 2) {
        cout << -1 << endl;
    } else if (u == v && u == 0) {
        cout << 0 << endl;
    } else if (u == v) {
        cout << 1 << endl;
        cout << u << endl;
    } else if (x & u) {
        cout << 3 << endl;
        cout << u << " " << x << " " << x << endl;
    } else {
        cout << 2 << endl;
        cout << u + x << " " << x << endl;
    }
}