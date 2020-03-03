//
// Created by misclicked on 3/2/20.
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
    int n, m;
    int a, b;
    while (cin >> T && T) {
        cin >> n >> m;
        while (T--) {
            cin >> a >> b;
            if (n == a || m == b) {
                puts("divisa");
            } else if (a > n && b > m) {
                puts("NE");
            } else if (a > n) {
                puts("SE");
            } else if (b > m) {
                puts("NO");
            } else {
                puts("SO");
            }
        }
    }
}