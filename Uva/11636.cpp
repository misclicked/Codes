//
// Created by misclicked on 3/4/20.
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
    ll n;
    for (int i = 1; cin >> n && n >= 0; i++) {
        ll now = 0;
        ll here = 1;
        while (here < n) {
            now++;
            here *= 2;
        }
        cout << "Case " << i << ": " << now << endl;
    }
}