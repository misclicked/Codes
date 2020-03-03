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
    cin >> T;
    ll a;
    multiset<ll> se;
    int cnt = 0;
    while (T--) {
        se.clear();
        for (int i = 0; i < 3; i++) {
            cin >> a;
            se.insert(a);
        }
        cout << "Case " << ++cnt << ": ";
        cout << *++se.begin() << endl;
    }
}