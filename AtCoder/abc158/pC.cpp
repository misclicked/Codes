//
// Created by misclicked on 3/7/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
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
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < 5000; i++) {
        if (floor(i * 0.08) == a && floor(i * 0.1) == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}