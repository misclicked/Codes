//
// Created by misclicked on 3/7/20.
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
    int n, T;
    cin >> T;
    vector<int> odd, even;
    while (T--) {
        cin >> n;
        odd.clear();
        even.clear();
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            if (data % 2 == 0)even.push_back(i + 1);
            else odd.push_back(i + 1);
        }
        if (even.size()) {
            cout << 1 << endl;
            cout << even[0] << endl;
        } else if (odd.size() >= 2) {
            cout << 2 << endl;
            cout << odd[0] << " " << odd[1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}