//
// Created by ISMP on 2020/3/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll ans = 0;
ll n, m;
vector<ll> vec;
ll dp[3005][3005];

void dfs(int i, ll P, ll succ) {
    if (succ < dp[i][P])return;
    ans = max(ans, succ);
    dp[i][P] = max(dp[i][P], succ);
    if (i >= n)return;
    if (P) {
        dfs(i + 1, P - min(P, vec[i]), succ + min(P, vec[i]));
    }
    if (P < m) {
        dfs(i + 1, min(m, P + vec[i]), succ);
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
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    ll data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        vec.push_back(min(data, m));
    }
    dfs(1, vec[0], 0);
    cout << ans << endl;
}