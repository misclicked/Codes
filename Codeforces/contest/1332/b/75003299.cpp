//
// Created by misclicked on 2020/4/1.
//

#include <bits/stdc++.h>
#include <tr1/hashtable_policy.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

unordered_map<int, int> mp;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T, n, d;
    cin >> T;
    int cur, now;
    vector<int> ans;
    while (T--) {
        cin >> n;
        cur = 0;
        mp.clear();
        ans.clear();
        for (int i = 0; i < n; i++) {
            cin >> d;
            for (int j = 0; j < 11; j++) {
                if (d % tr1::__detail::__prime_list[j] == 0) {
                    if (mp.count(tr1::__detail::__prime_list[j])) {
                        now = mp[tr1::__detail::__prime_list[j]];
                    } else {
                        now = ++cur;
                        mp[tr1::__detail::__prime_list[j]] = now;
                    }
                    break;
                }
            }
            ans.emplace_back(now);
        }
        cout << cur << endl;
        for (auto it:ans)cout << it << " ";
        cout << endl;
    }
}