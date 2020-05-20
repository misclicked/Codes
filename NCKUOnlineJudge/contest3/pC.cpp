//
// Created by ISMP on 2020/4/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MAX_N 100000

pii fa[2 * MAX_N + 5];

pii find(int x) {
    while (fa[x].first != x) {
        fa[x] = fa[fa[x].first];
        x = fa[x].first;
    }
    return fa[x];
}

void unite(int x, int y) {
    pii X = find(x);
    pii Y = find(y);
    fa[Y.first] = X;
    fa[Y.second] = {X.second, X.first};
}

void en(int x, int y) {
    pii X = find(x);
    pii Y = find(y);
    fa[Y.first] = {X.second, X.first};;
    fa[Y.second] = X;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b, c;
    for (int i = 0; i < n; i++) {
        fa[i] = {i, MAX_N + 1 + i};
        fa[MAX_N + 1 + i] = {MAX_N + 1 + i, i};
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            if (find(b) != find(c) && find(b).first != b && find(c).first != c) {
                puts("nani");
            } else {
                unite(b, c);
            }
        } else if (a == 2) {
            if (find(b) == find(c) && find(b).first != b && find(c).first != c) {
                puts("nani");
            } else {
                en(b, c);
            }
        } else {
            if (find(b).first != find(c).first
                && find(b).first != find(c).second
                && find(c).first != find(b).second) {
                puts("none");
            } else if (find(b) == find(c)) {
                puts("friend");
            } else {
                puts("enemy");
            }
        }
    }
}