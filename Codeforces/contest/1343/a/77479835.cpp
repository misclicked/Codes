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
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll now = 4, here = 3;
        while (true) {
            if (n % here == 0) {
                break;
            }
            here += now;
            now *= 2;
        }
        cout << n / here << endl;
    }

}