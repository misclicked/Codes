//
// Created by misclicked on 2/6/20.
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
    int t, n;
    vector<int> vec;
    cin >> t;
    while (t--) {
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        auto odd{0}, even{0};
        for (auto it:vec) {
            if (it % 2)odd++;
            else even++;
        }
        cerr << odd << " " << even << endl;
        if (odd == 0) {
            cout << "NO" << endl;
        } else if (even && odd) {
            cout << "YES" << endl;
        } else if (odd % 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}