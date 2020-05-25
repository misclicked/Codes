//
// Created by misclicked on 2020/3/14.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll deg[200005];
ll par[200005];
vector<ll> G[200005];
unordered_map<ll, ll> mape;
vector<pii> inp;

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
    ll a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        inp.push_back({a, b});
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    ll TreeTop = -1;
    ll maxD = -1;
    for (int i = 1; i < n; i++) {
        if (deg[i] > maxD) {
            maxD = deg[i];
            TreeTop = i;
        }
    }
    queue<int> que;
    que.push(TreeTop);
    memset(par, 0, sizeof(par));
    par[TreeTop] = 0;
    ll here = 0;
    while (que.size()) {
        ll now = que.front();
        que.pop();
        for (auto it:G[now]) {
            if (it != par[now]) {
                mape[min(now, it) * 1000000ll + max(now, it)] = here++;
                par[it] = now;
                que.push(it);
            }
        }
    }
    for (auto it:inp) {
        cout << mape[min(it.first, it.second) * 1000000ll + max(it.first, it.second)] << endl;
    }
}