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

int mp[55][55];

ll n, m, a, b;

int main() {
#ifdef OUO
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
        cin >> n >> m >> a >> b;
        int base = 0;
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a; j++) {
                mp[i][(base + j) % m] = 1;
            }
            base += a;
        }
        string ans = "YES";
        for (int i = 0; i < m; i++) {
            int now = 0;
            for (int j = 0; j < n; j++) {
                if (mp[j][i] == 1)now++;
            }
            if (now != b)ans = "NO";
        }
        cout << ans << endl;
        if (ans == "YES")
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    cout << mp[i][j];
                cout << endl;
            }
    }
}