//
// Created by misclicked on 2/11/20.
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
    vector<int> vec;
    cin >> n;
    ll sum{0};
    vec.resize(n);
    for (auto &it:vec) {
        cin >> it;
        sum += it;
    }
    ll now{0};
    for (int i = 1; i <= n; i++) {
        now += vec[i - 1];
        if (now * 2 >= sum) {
            cout << i << endl;
            exit(0);
        }
    }
}