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
    set<int> se;
    while (T--) {
        int n;
        int Min = 200;
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            Min = min(vec[i], Min);
        }
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            vec[i] -= Min;
            if (vec[i] & 1)ans = "NO";
        }
        cout << ans << endl;

    }
}