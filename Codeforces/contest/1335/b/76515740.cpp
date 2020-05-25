//
// Created by misclicked on 2020/4/13.
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
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        string base = "";
        char c = 'a';
        for (int i = 0; i < b; i++) {
            base.push_back(c + i);
        }
        int now = base.size();
        for (int i = 0; i < n; i++) {
            cout << base[i % now];
        }
        cout << endl;
    }
}