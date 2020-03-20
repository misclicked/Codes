//
// Created by misclicked on 3/5/20.
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
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int L, R;
        L = -1, R = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (L == -1)L = i;
                R = i;
            }
        }
        int ans = 0;
        for (int i = L; i <= R; i++) {
            if (s[i] == '0')ans++;
        }
        cout << ans << endl;
    }
}