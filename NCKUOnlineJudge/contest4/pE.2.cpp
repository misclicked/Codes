//
// Created by ISMP on 2020/4/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define L 1048576
char _buf[L], *S, *T, _buf1[L], *S1 = _buf1;
ll dp[300005] = {0};
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
    for (int i = 2; i <= n + 1; i++) {
        get(vec[i]);
    }
    for (int i = 2; i <= n + 1; i++) {
        ll now = 0;
        cout << "i: " << i << endl;
        vector<int> vv;
        for (int j = i, len = 0; j >= 2 && len < k - 1; j--, len++) {
            now += vec[j];
            vv.push_back(vec[j]);
            cout << j - 2 << " " << dp[j - 2];
            for (auto it:vv) {
                cout << " " << it;
            }
            cout << endl;
            dp[i] = max(dp[i], dp[j - 2] + now);
        }
    }
    printf("%lld", dp[n + 1]);
    return 0;
}