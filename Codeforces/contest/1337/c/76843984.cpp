//
// Created by misclicked on 2020/4/15.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<int> G[200005];
pii dis[200005];

int dfs(int now, int par) {
    int childs = 0;
    for (auto it:G[now]) {
        if (it == par)continue;
        dis[it].first = dis[now].first + 1;
        dis[it].second += dfs(it, now);
        childs += dis[it].second;
    }
    return childs + 1;
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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(dis, 0, sizeof(dis));
    dis[1].first = 0;
    dis[1].second = n;
    vector<int> vec;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        dis[i].second--;
        vec.push_back(dis[i].first - dis[i].second);
        //cout << i << " " << dis[i].first << " " << dis[i].second << endl;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += vec[i];
        //cout << vec[i] << endl;
    }
    cout << ans << endl;
}