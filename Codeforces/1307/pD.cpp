//
// Created by misclicked on 2/21/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

unordered_set<ll> ss;
vector<ll> G[200005];
vector<ll> inp, path;
ll vis[200005] = {0};
ll dis[200005] = {0};
ll dis2[200005] = {0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n, m, k, a, b;
    cin >> n >> m >> k;
    for (ll i = 0; i < k; i++) {
        cin >> a;
        inp.push_back(a);
        ss.insert(a);
    }
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<ll> que;
    que.push(1);
    vis[1] = true;
    while (que.size()) {
        ll u = que.front();
        que.pop();
        for (auto v:G[u]) {
            if (!vis[v]) {
                vis[v] = true;
                que.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    que.push(n);
    memset(vis, 0, sizeof(vis));
    vis[n] = true;
    while (que.size()) {
        ll u = que.front();
        que.pop();
        for (auto v:G[u]) {
            if (!vis[v]) {
                vis[v] = true;
                que.push(v);
                dis2[v] = dis2[u] + 1;
            }
        }
    }
    ll best = 1;
    ll now = INT_MIN;
    vector<pii> vec;
    for (int i = 0; i < k; i++)vec.push_back({dis[inp[i]] - dis2[inp[i]], inp[i]});
    sort(vec.begin(), vec.end());
    for (auto it:vec) {
        int id = it.second;
        best = max(best, dis2[id] + now);
        now = max(now, dis[id]);
    }
    cerr << best + 1 << " " << dis[n] << endl;
    cout << min(best + 1, dis[n]) << endl;
}