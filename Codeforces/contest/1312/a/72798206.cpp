//
// Created by misclicked on 2020/3/9.
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
        int a, b;
        cin >> a >> b;
        if (a % b == 0 && a >= b)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}