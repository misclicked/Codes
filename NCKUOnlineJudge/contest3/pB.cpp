//
// Created by ISMP on 2020/4/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int S(int n) {
    if (n < 10)return n;
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return S(s);
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
    int n;
    ll k, x;
    cin >> n;
    while (n--) {
        cin >> k >> x;
        cout << x + (k - 1) * 9 << endl;
    }
}