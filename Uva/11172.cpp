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
    ll T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a > b)puts(">");
        else if (a < b)puts("<");
        else puts("=");
    }
}