//
// Created by misclicked on 2020/3/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
const int N = 1e5;
int n, m;
int t[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r) {
    int res = -1;
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
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[n + i];
    }
    build();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            modify(b - 1, c);
        } else {
            cout << query(b - 1, c) << endl;
        }
    }
}