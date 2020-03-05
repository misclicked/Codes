//
// Created by ISMP on 2020/3/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<pii> G[100005];
ll d[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)d[i] = -1;
    d[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 0});
    while (pq.size()) {
        pii now = pq.top();
        pq.pop();
        ll nowcost = now.first;
        ll nownode = now.second;
        if (d[nownode] != -1 && d[nownode] < nowcost)continue;
        for (auto it:G[nownode]) {
            if (d[it.first] == -1) {
                d[it.first] = d[nownode] + it.second;
                pq.push({d[it.first], it.first});
            } else if ((d[nownode] + it.second) < d[it.first]) {
                d[it.first] = (d[nownode] + it.second);
                pq.push({d[it.first], it.first});
            }
        }
    }
    cout << d[0];
    for (int i = 1; i < n; i++) {
        cout << " " << d[i];
    }
    cout << endl;
}
