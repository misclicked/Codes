//
// Created by misclicked on 2/6/20.
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
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        auto ans{0ll};
        while (n) {
            if (n > 9) {
                ans += n - n % 10;
                n = n / 10 + n % 10;
            } else {
                ans += n;
                n = 0;
            }
        }
        cout << ans << endl;
    }
}