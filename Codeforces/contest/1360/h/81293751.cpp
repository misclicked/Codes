//
// Created by misclicked on 2020/5/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, string> pls;

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
    int t;
    cin >> t;
    vector<pls> vec;
    unordered_set<ll> se;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll base = pow(2ll, m);
        string s;
        se.clear();
        ll median = base / 2 - 1;
        ll sz = base;
        base /= 2;
        for (int i = 0; i < n; i++) {
            cin >> s;
            ll here = base;
            ll now = 0;
            for (int j = 0; j < m; j++) {
                if (s[j] == '1')now += here;
                here /= 2;
            }
            se.insert(now);
            //cout << sz << " " << now << " " << median << endl;
            if (now < median) {
                if (sz % 2 == 0) {
                    median++;
                    while (se.count(median))median++;
                }
            } else if (now > median) {
                if (sz % 2 == 1) {
                    median--;
                    while (se.count(median))median--;
                }
            } else {
                if (sz % 2 == 0) {
                    median++;
                    while (se.count(median))median++;
                } else {
                    median--;
                    while (se.count(median))median--;
                }
            }
            sz--;
        }
        bitset<64> b(median);
        string ans = b.to_string();
        reverse(ans.begin(), ans.end());
        ans = ans.substr(0, m);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}