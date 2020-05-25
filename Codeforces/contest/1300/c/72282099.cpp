//
// Created by ISMP on 2020/3/3.
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
    cin >> n;
    vector<ll> input, ft, ed;
    ft.resize(n + 1);
    ed.resize(n + 1);
    ll data;
    for (ll i = 0; i < n; i++) {
        cin >> data;
        input.push_back(data);
    }
    ft[0] = ~0;
    ed[n] = ~0;
    for (ll i = 0; i < n; i++) {
        ft[i + 1] = ft[i] & ~input[i];
    }
    for (ll i = n - 1; i > 0; i--) {
        ed[i] = ed[i + 1] & ~input[i];
    }
    int elect;
    ll mex = -1;
    for (ll i = 0; i < n; i++) {
        ll now = input[i] & ft[i] & ed[i + 1];
        if (now > mex) {
            mex = now;
            elect = i;
        }
    }
    cout << input[elect];
    for (int i = 0; i < n; i++) {
        if (i == elect)continue;
        cout << " " << input[i];
    }
}