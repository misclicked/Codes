//
// Created by misclicked on 2020/4/3.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int mp[1005];

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
    int n, x;
    cin >> T;
    int d;
    while (T--) {
        memset(mp, 0, sizeof(mp));
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> d;
            mp[d]++;
        }
        int i;
        for (i = 1; x; i++) {
            if (!mp[i]) {
                x--;
            }
        }
        for (; mp[i]; i++) {

        }
        cout << i - 1 << endl;
    }
}