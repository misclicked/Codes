//
// Created by misclicked on 2/25/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

unordered_set<int> ss;
vector<int> G[200005];
vector<int> inp, path;
int vis[200005] = {0};
int dis[200005] = {0};
int dis2[200005] = {0};
int DIS[5005][5005] = {0};
int VIS[5005] = {0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a;
        inp.push_back(a);
        ss.insert(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    que.push(1);
    vis[1] = true;
    while (que.size()) {
        int u = que.front();
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
        int u = que.front();
        que.pop();
        for (auto v:G[u]) {
            if (!vis[v]) {
                vis[v] = true;
                que.push(v);
                dis2[v] = dis2[u] + 1;
            }
        }
    }
    int best = 1;
    int now = INT_MIN;
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
    if (n <= 5e4 && k <= 5e4) {
        memset(DIS, 0, sizeof(DIS));
        for (int i = 1; i <= n; i++) {
            que.push(i);
            memset(VIS, 0, sizeof(VIS));
            VIS[i] = true;
            while (que.size()) {
                int u = que.front();
                que.pop();
                for (auto v:G[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        que.push(v);
                        DIS[i][v] = DIS[i][u] + 1;
                    }
                }
            }
        }
        int Min, Mini, Minj, Ans;
        Min = INT_MAX;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (DIS[inp[i]][inp[j]] <= Min) {
                    Min = DIS[inp[i]][inp[j]];
                    Ans = min(dis[inp[i]] + dis2[inp[j]], dis[inp[j]] + dis2[inp[i]]);
                }
            }
        }
        if (min(best + 1, dis[n]) != min(Ans + 1, dis[n])) {
            cout << Ans + 1 << " " << dis[n] << endl;
        }
    }
}