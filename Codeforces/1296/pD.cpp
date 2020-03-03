//
// Created by misclicked on 2/14/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;


#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, a, b, k, data, ans{0};
    vector<int> vec;
    cin >> n >> a >> b >> k;
    for (int i = 0; i < n; i++) {
        cin >> data;
        int now = data % (a + b);
        if (now == 0)now = a + b;
        now -= a;
        cerr << ceil((now * 1.0) / a) << endl;
        vec.push_back(ceil((now * 1.0) / a));
    }
    sort(vec.begin(), vec.end());
    for (auto it:vec) {
        if (it <= 0)ans++;
        else if (k >= it)ans++, k -= it;
    }
    cout << ans << endl;
}