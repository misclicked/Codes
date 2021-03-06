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
    ll c[505];
    ll n;
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 500; j - i >= 0; j--) {
            c[j] += c[j - i];
        }
    }
    while (cin >> n) {
        cout << c[n] << endl;
    }
}