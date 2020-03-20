//
// Created by misclicked on 3/12/20.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
using namespace __gnu_pbds;
typedef tree<
        double,
        null_type,
        less_equal<double>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

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
    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a, b;
    vector<int> c, d;
    ordered_set se;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        c.push_back(a[i] - b[i]);
        d.push_back(b[i] - a[i]);
    }
    ll ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        se.insert(d[i + 1]);
        ans += se.order_of_key((double) c[i] - 0.1);
    }
    cout << ans << endl;
}