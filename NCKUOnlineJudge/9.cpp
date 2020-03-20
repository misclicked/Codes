//
// Created by misclicked on 3/4/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
const int N = 1e5;
int n;
int t[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, t[l++]);
        if (r & 1) res = max(res, t[--r]);
    }
    return res;
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
    int n, m;
    cin >> n >> m;
    build();
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a;
        modify(i, a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 2) {
            cout << query(b, c) << endl;
        } else {
            modify(b, c);
        }
    }
}