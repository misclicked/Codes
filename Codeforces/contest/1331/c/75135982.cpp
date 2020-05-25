//
// Created by misclicked on 2020/4/1.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

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
    bitset<6> bt(n);
    //cout << bt << endl;
    int ans = bt[4] * 1 + bt[1] * 2 + bt[3] * 4 + bt[2] * 8 + bt[0] * 16 + bt[5] * 32;
    cout << ans << endl;
}