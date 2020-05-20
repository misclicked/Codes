//
// Created by ISMP on 2020/4/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll ansA, ansB, dpL[100005], dpR[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    string a, b;
    ll n;
    cin >> n;
    cin >> a >> b;
    memset(dpL, 0, sizeof(dpL));
    memset(dpR, 0, sizeof(dpR));
    for (int i = 1; i <= n; i++) {
        dpL[i] = dpL[i - 1] + (a[i - 1] == 'A');
    }
    for (int i = n - 2; i >= 0; i--) {
        dpR[i] = dpR[i + 1] + (a[i + 1] == 'A');
    }
    ansA = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'K') {
            ansA += dpL[i] * dpR[i];
        }
    }
    memset(dpL, 0, sizeof(dpL));
    memset(dpR, 0, sizeof(dpR));
    for (int i = 1; i <= n; i++) {
        dpL[i] = dpL[i - 1] + (b[i - 1] == 'A');
    }
    for (int i = n - 2; i >= 0; i--) {
        dpR[i] = dpR[i + 1] + (b[i + 1] == 'A');
    }
    ansB = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 'K') {
            ansB += dpL[i] * dpR[i];
        }
    }
    if (ansA > ansB) {
        cout << "LanA WIN\n";
    } else if (ansA < ansB) {
        cout << "LanE WIN\n";
    } else {
        cout << "WINWIN\n";
    }
}