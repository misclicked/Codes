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
    int T;
    cin >> T;
    vector<ll> vec;
    while (T--) {
        ll n;
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        ll ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            ans = min(ans, vec[i] - vec[i - 1]);
        }
        cout << ans << endl;
    }
}