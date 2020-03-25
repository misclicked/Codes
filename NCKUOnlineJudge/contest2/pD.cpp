//
// Created by ISMP on 2020/3/25.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> vec;
    ll data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        vec.push_back(data);
    }
    priority_queue<pipii, vector<pipii>, greater<pipii> > hehe;
    for (int i = 1; i < n; i++) {
        hehe.push({vec[i] - vec[i - 1] - 1, {vec[i], vec[i - 1]}});
    }
    ll ans = 0;
    ll now = hehe.size() + 1;
    while (now > k) {
        ans += hehe.top().first;
        hehe.pop();
        k--;
        now -= 2;
    }
    cout << ans + n << endl;
}