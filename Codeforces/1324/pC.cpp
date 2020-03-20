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
    vector<int> vec;
    while (T--) {
        string s;
        cin >> s;
        vec.clear();
        vec.push_back(0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R')vec.push_back(i + 1);
        }
        vec.push_back(s.size() + 1);
        int ans = 0;
        for (int i = 0; i < vec.size() - 1; i++) {
            ans = max(vec[i + 1] - vec[i], ans);
        }
        cout << ans << endl;
    }
}