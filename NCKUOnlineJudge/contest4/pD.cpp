//
// Created by ISMP on 2020/4/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plpll;

vector<int> vec;

int dp[1005][1005];

int main() {
    freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll d;
        cin >> d;
        vec.push_back(d);
        dp[i][i] = d;
    }
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            dp[l][r] += min(dp[l - 1][r], dp[l][r + 1]);
        }
    }
    for (int l = 1; l <= n; l++) {
        for (int r = 1; r <= n; r++) {
            cout << dp[l][r] << " ";
        }
        cout << endl;
    }
}