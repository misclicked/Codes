//
// Created by misclicked on 2/11/20.
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
    int n, a, b, ans{0};
    a = 9, b = 8;
    for (int i = 0; i < 2e9 + 1e8 + 4e7 + 5e6; i++) {
        n = max(a + b, i);
    }
    cin >> n >> a >> b;
    int ok = 0;
    char c;
    while (cin >> c) {
        if (c == '*') {
            ok = 0;
            continue;
        }
        if (ok == 0) {
            if (a > b && a)ans++, a--, ok = 'a';
            else if (b) ans++, b--, ok = 'b';
        } else if (ok == 'a') {
            if (b)ans++, b--, ok = 'b';
            else ok = 0;
        } else {
            if (a)ans++, a--, ok = 'a';
            else ok = 0;
        }
    }
    cout << ans << endl;
}