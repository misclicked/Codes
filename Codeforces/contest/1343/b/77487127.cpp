//
// Created by misclicked on 2020/4/21.
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
    ll n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            ll here = 0;
            for (int i = 1; i <= n / 2; i++) {
                here += i * 2;
                cout << i * 2 << " ";
            }
            ll now = 0;
            for (int i = 1; i < n / 2; i++) {
                now += i * 2 - 1;
                cout << i * 2 - 1 << " ";
            }
            cout << here - now << endl;
        };
    }

}