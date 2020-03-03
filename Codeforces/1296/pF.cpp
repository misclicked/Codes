//
// Created by misclicked on 2/19/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct piii {
    int a, b, c;
};

struct edge {
    int u, v, cost;
};

#define MAX_N 5005
#define MAX_LOG_N 13

vector<edge> Edges;
vector<int> G[5005];
int n, logn, depth[MAX_N], parent[MAX_LOG_N][MAX_N];

int fullfill[MAX_N] = {0};

void DFS(int u, int par, int dep) {
    depth[u] = dep;
    parent[0][u] = par;
    for (auto v:G[u]) {
        if (v != par) {
            DFS(v, u, dep + 1);
        }
    }
}

void build() {
    memset(depth, 0, sizeof(depth));
    memset(parent, 0, sizeof(parent));
    DFS(1, 0, 0);
    for (int i = 0; i <= logn; i++) {
        for (int u = 1; u <= n; u++) {
            if (parent[i][u] == 0)parent[i + 1][u] = 0;
            else parent[i + 1][u] = parent[i][parent[i][u]];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = logn - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            v = parent[i][v];
        }
    }
    if (u == v)return u;
    int ret = 0;
    for (int i = logn - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        } else {
            ret = parent[i][u];
        }
    }
    return ret;
}

int dis(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

bool belong(int u1, int v1, int u2, int v2) {
    return ((dis(u2, v1) + dis(v1, v2)) == dis(u2, v2)) &&
           ((dis(u2, u1) + dis(u1, v2)) == dis(u2, v2));
}


#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<piii> input;
vector<piii> inp;
map<pii, int> se;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        input.push_back({a, b, 0});
        se[{a, b}] = 1000000;
    }
    int q, c;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        inp.push_back({min(a, b), max(a, b), c});
    }
    logn = log2(n);
    build();
    sort(inp.begin(), inp.end(), [](piii &a, piii &b) {
        if (dis(a.a, a.b) != dis(b.a, b.b)) {
            return dis(a.a, a.b) < dis(b.a, b.b);
        } else {
            return a.c < b.c;
        }
    });

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < q; j++) {
            if (belong(input[i].a, input[i].b, inp[j].a, inp[j].b))
                input[i].c++;
        }
    }
    sort(input.begin(), input.end(), [](piii &a, piii &b) {
        return a.c < b.c;
    });
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        bool set = false;
        bool be = false;
        bool ok = true;
        cerr << input[i].a << " " << input[i].b << endl;
        for (int j = 0; j < q; j++) {
            cerr << "range: " << inp[j].a << " " << inp[j].b << endl;
            if (belong(input[i].a, input[i].b, inp[j].a, inp[j].b)) {
                be = true;
                cerr << inp[j].c << " " << se[{input[i].a, input[i].b}] << endl;
                if (inp[j].c > se[{input[i].a, input[i].b}]) {
                    cout << "-1" << endl;
                    return 0;
                } else if (!set && !fullfill[j]) {
                    se[{input[i].a, input[i].b}] = inp[j].c;
                    fullfill[j] = true;
                    set = true;
                }
                if (!fullfill[j] && se[{input[i].a, input[i].b}] == inp[j].c) {
                    fullfill[j] = true;
                }
            }
        }
        ans.push_back(se[{input[i].a, input[i].b}]);
    }
    for (int i = 0; i < q; i++) {
        if (!fullfill[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
}