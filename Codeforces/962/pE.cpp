//
// Created by misclicked on 2/12/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<pii> PB, PR, PP;
unordered_map<int, char> vec;
unordered_map<int, int> bigpp;
struct edge {
    ll u, v, cost;
};

#define MAX_N 400005
#define BASS 200001
int d[MAX_N];
int group;

void initialize(int n) {
    for (int i = 0; i < n; i++)
        d[i] = i;
    group = n;
}

int Find(int x) {
    return d[x] == x ? x : d[x] = Find(d[x]);
}

void Union(int x, int y) {
    d[Find(x)] = Find(y);
    group--;
}

bool IsSame(int x, int y) {
    return Find(x) == Find(y);
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
    ll n;
    cin >> n;
    ll ans = 0;
    group = n;
    for (ll i = 0; i < n; i++) {
        ll idx;
        char ch;
        cin >> idx >> ch;
        if (ch == 'P') {
            PP.push_back({idx, i});
            PB.push_back({idx, i});
            PR.push_back({idx, i});
        } else if (ch == 'B') {
            PB.push_back({idx, i});
        } else {
            PR.push_back({idx, i});
        }
        vec[i] = ch;
        if (ch == 'P') {
            vec[group] = ch;
            bigpp[i] = group;
            bigpp[group] = i;
            group++;
        }
    }
    vector<edge> Edges;
    for (int i = 0; i < (int) PB.size() - 1; i++) {
        if (vec[PB[i].second] == 'B' || vec[PB[i + 1].second] == 'B') {
            Edges.push_back({PB[i].second, PB[i + 1].second,
                             PB[i + 1].first - PB[i].first});
        }
    }
    for (int i = 0; i < (int) PR.size() - 1; i++) {
        if (vec[PR[i].second] == 'R' || vec[PR[i + 1].second] == 'R') {
            Edges.push_back({PR[i].second, PR[i + 1].second,
                             PR[i + 1].first - PR[i].first});
        }
    }
    for (int i = 0; i < (int) PP.size() - 1; i++) {
        Edges.push_back({PP[i].second, PP[i + 1].second,
                         PP[i + 1].first - PP[i].first});
    }
    if (Edges.size()) {
        sort(Edges.begin(), Edges.end(),
             [](const edge &a, const edge &b) {
                 return a.cost < b.cost;
             });
        initialize(group);
        if (n == PB.size() || n == PR.size() || true) {
            for (int i = 0; i < (int) PP.size() - 1; i++) {
                Union(PP[i].second, PP[i + 1].second);
                Union(bigpp[PP[i].second], bigpp[PP[i + 1].second]);
                ans += PP[i + 1].first - PP[i].first;
            }
        }
        for (int i = 0; i < Edges.size(); i++) {
            ll u = Edges[i].u;
            ll v = Edges[i].v;
            ll c = Edges[i].cost;
            cerr << u << " " << v << " " << c << endl;
            if (!(vec[u] == 'R' && vec[v] == 'B' || vec[u] == 'R' && vec[v] == 'B')
                && !IsSame(u, v)) {
                if (vec[u] == 'R' && vec[v] == 'P' || vec[u] == 'P' && vec[v] == 'R') {
                    ans += c;
                    Union(u, v);
                } else if (vec[u] == 'B' && vec[v] == 'P' || vec[u] == 'P' && vec[v] == 'B') {
                    if (vec[v] == 'P') {
                        ans += c;
                        Union(u, bigpp[v]);
                    } else {
                        ans += c;
                        Union(bigpp[u], v);
                    }
                } else if (vec[u] == 'P' && vec[v] == 'P') {
                    ans += c;
                    Union(u, v);
                    Union(bigpp[u], bigpp[v]);
                } else {
                    ans += c;
                    Union(u, v);
                }

            }
            if (group == 2)break;
        }
        cout << ans << endl;
    }
}