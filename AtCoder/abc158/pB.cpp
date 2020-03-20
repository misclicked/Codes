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
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = (a / (b + c)) * b;
    if ((a % (b + c)) > b) {
        ans += b;
    } else {
        ans += a % (c + b);
    }
    cout << ans << endl;
}