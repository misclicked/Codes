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

string s[15];

int TT(string ss, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < ss.size(); j++) {
            if (ss[j] != s[i][j]) {
                now++;
            }
        }
        ret = max(now, ret);
    }
    return ret;
}

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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        string ans = "-1";
        for (int i = 0; i < m; i++) {
            string test = s[0];
            if (ans != "-1")break;
            for (int j = 'a'; j <= 'z'; j++) {
                test[i] = j;
                if (TT(test, n) <= 1) {
                    ans = test;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}