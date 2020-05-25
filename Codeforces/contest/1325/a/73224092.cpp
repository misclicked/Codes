//
// Created by misclicked on 2020/3/14.
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
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << endl;
        } else {
            cout << 1 << " " << n - 1 << endl;
        }
    }
}