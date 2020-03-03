//
// Created by misclicked on 2/14/20.
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
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    cout << fixed << (int) ceil((ceil((n * 1.0) / s) * k) / (p * 1.0)) << endl;
}