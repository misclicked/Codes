//
// Created by misclicked on 3/19/20.
//
#pragma GCC optimize("Os")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int dp[2005][2005];
unordered_map<int, int> mp;

int main() {
    srand(time(0));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, q;
    while (cin >> n) {
        if (n == 0)break;
        int data;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dp[i][j];
            }
        }
        cin >> q;
        int r1, r2, c1, c2;
        while (q--) {
            cin >> r1 >> r2 >> c1 >> c2;
            mp.clear();
            for (int i = 0; i < 10000000; i++) {
                int x = rand() % (r2 - r1 + 1) + r1;
                int y = rand() % (c2 - c1 + 1) + c1;
                mp[dp[x][y]]++;
            }
            int mx, ans;
            mx = 0;
            for (auto it:mp) {
                if (it.second > mx) {
                    mx = it.second;
                    ans = it.first;
                }
            }
            //cout << mx << " " << endl;
            if (mx > 5010000) {
                cout << ans << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}