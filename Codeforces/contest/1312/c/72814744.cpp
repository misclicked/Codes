//
// Created by misclicked on 2020/3/9.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
unordered_set<ll> se;

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
    cin >> T;
    while (T--) {
        string ans = "YES";
        int n, k;
        cin >> n >> k;
        se.clear();
        for (int i = 0; i < n; i++) {
            ll data;
            cin >> data;
            int now = 0;
            if (data != 0 && data != 1) {
                if (data % k != 1 && data % k != 0)ans = "NO";
            }
            while (data) {
                if (data % k == 1) {
                    if (se.count(now))ans = "NO";
                    se.insert(now);
                } else if (data % k) {
                    ans = "NO";
                }
                data /= k;
                now++;
            }
        }
        cout << ans << endl;
    }
}