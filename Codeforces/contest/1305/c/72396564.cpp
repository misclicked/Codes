//
// Created by misclicked on 3/4/20.
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
    int n, m;
    cin >> n >> m;
    if (n > m)cout << 0 << endl;
    else {
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            ll data;
            cin >> data;
            vec.push_back(data);
        }
        ll ans = 1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = (ans * abs(vec[i] - vec[j])) % m;
            }
        }
        cout << ans << endl;
    }
}