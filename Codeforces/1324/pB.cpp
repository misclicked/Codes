//
// Created by misclicked on 3/12/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
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
    int T;
    cin >> T;
    int n;
    vector<int> vec;
    unordered_map<int, int> mp;
    while (T--) {
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        string ans = "NO";
        mp.clear();
        for (int i = 0; i < n; i++) {
            if (!mp.count(vec[i])) {
                mp[vec[i]] = i;
            } else {
                if ((i - mp[vec[i]]) > 1) {
                    ans = "YES";
                }
            }
        }
        cout << ans << endl;
    }
}