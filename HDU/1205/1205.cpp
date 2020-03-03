//
// Created by misclicked on 2/27/20.
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
    ll T;
    cin >> T;
    vector<ll> vec;
    while (T--) {
        ll n;
        cin >> n;
        string s;
        vec.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        s = "Yes";
        ll now = vec[0];
        for (ll i = 1; i < n; i++) {
            if (vec[i] - now > 1) {
                s = "No";
                break;
            }
            now += vec[i];
            now = min(now, 1000005ll);
        }
        if (n == 1 && vec[0] != 1)s = "No";
        cout << s << endl;
        vec.clear();
    }
}