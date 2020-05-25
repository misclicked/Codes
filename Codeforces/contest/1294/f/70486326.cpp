//
// Created by misclicked on 2/7/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MAX_V 200005

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int parent[200005];
int farest;
int fardep;
int ans;
int pointA, pointB;
vector<int> G[MAX_V];
unordered_set<int> inside;

void dfs(int now, int dep, int par) {
    parent[now] = par;
    if (dep > fardep) {
        fardep = dep;
        farest = now;
    }
    for (int u:G[now]) {
        if (u != par) {
            dfs(u, dep + 1, now);
        }
    }
}

void dfsol(int now, int dep, int par) {
    if (dep > fardep) {
        fardep = dep;
        farest = now;
    }
    for (int u:G[now]) {
        if (u != par) {
            if (!inside.count(u))
                dfsol(u, dep + 1, now);
            else
                dfsol(u, dep, now);
        }
    }
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
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans = farest = fardep = 0;
    dfs(1, 0, 0);
    cerr << "fardep: " << fardep << " ferest: " << farest << endl;
    pointA = farest;
    farest = fardep = 0;
    dfs(pointA, 0, 0);
    cerr << "fardep: " << fardep << " ferest: " << farest << endl;
    pointB = farest;
    ans = fardep;
    while (parent[farest]) {
        inside.insert(parent[farest]);
        farest = parent[farest];
    }
    inside.insert(pointB);
    for (auto it:inside)cerr << it << " ";
    cerr << endl;
    farest = fardep = 0;
    dfsol(pointA, 0, 0);
    cerr << "fardep: " << fardep << " ferest: " << farest << endl;
    ans += fardep;
    if (farest == 0) {
        for (int i = 1; i <= n; i++) {
            if (i != pointA && i != pointB) {
                farest = i;
                break;
            }
        }
    }
    cout << ans << endl << pointA << " " << pointB << " " << farest;
}