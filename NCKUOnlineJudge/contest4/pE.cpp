//
// Created by ISMP on 2020/4/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define L 1048576
char _buf[L], *S, *T, _buf1[L], *S1 = _buf1;
ll dp[300005][2] = {0};
ll vec[300005] = {0};

inline char gc() {
    if (S == T) {
        T = (S = _buf) + fread(_buf, 1, L, stdin);
        if (S == T)return 0;
    }
    return *S++;
}

char c;

void get(ll &x) {
    for (c = gc(); (c < '0' || c > '9') && c != '-'; c = gc());
    for (x = c ^ '0', c = gc(); c >= '0' && c <= '9'; c = gc())x = (x << 3) + (x << 1) + (c ^ '0');
}

int main() {
    freopen("input.txt", "r", stdin);
    ll n, k;
    get(n);
    get(k);
    for (int i = 1; i <= n; i++) {
        get(vec[i]);
    }
    deque<pii> dq;
    dq.emplace_back(vec[1], 1);
    dp[1][0] = 0;
    dp[1][1] = vec[i];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] + vec[i + 1];
        while (dq.size() && dq.back().first < dp[i - 1][0])dq.pop_back();
        dq.emplace_back(dp[i - 1][0], i - 1);
        if (dq.front().second == i - k) dq.pop_front();
        dp[i][1] = vec[i] + dq.front().first;
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}