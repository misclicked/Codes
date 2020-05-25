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

string s[55];

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
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        string ans = "YES";
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (s[i][j] == '1') {
                    if (!(s[i][j + 1] == '1' || s[i + 1][j] == '1'))
                        ans = "NO";
                }
            }
        }
        cout << ans << endl;
    }
}