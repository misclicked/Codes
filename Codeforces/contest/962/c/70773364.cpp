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

ll calc(ll a, ll b) {
    string A = to_string(a);
    string B = to_string(b);
    int cnt = 0;
    ll ret = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[cnt]) {
            cnt++;
            ret++;
        }
    }
    if (cnt == B.size())cerr << B << endl;
    return cnt == B.size() ? A.size() - ret : LLONG_MAX;
}

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
    ll ans = LLONG_MAX;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
        ans = min(ans, calc(n, i * i));
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}