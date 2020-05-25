//
// Created by misclicked on 2/21/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll mape[256] = {0};
ll sol[256][256];

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
    string s;
    cin >> s;
    memset(sol, 0, sizeof(sol));
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 'a'; j <= 'z'; j++) {
            sol[s[i]][j] += mape[j];
        }
        mape[s[i]]++;
    }
    ll ans = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (sol[i][j])
                cerr << i << " " << j << " " << sol[i][j] << endl;
            ans = max(ans, sol[i][j]);
        }
        ans = max(ans, mape[i]);
    }
    cout << ans << endl;
}