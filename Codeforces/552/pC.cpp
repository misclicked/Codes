//
// Created by ISMP on 2020/3/3.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<ll> vec;
ll n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin >> n >> m;
    while (m) {
        vec.push_back(m % n);
        m /= n;
    }
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] <= 1)continue;
        if (vec[i] == n - 1) {
            vec[i] = 0;
            if (i + 1 == vec.size()) {
                vec.push_back(1);
            } else {
                vec[i + 1]++;
            }
            continue;
        }
        if (vec[i] == n) {
            vec[i] = 0;
            if (i + 1 == vec.size()) {
                vec.push_back(1);
            } else {
                vec[i + 1]++;
            }
            continue;
        }
        cout << "NO" << endl;
        exit(0);
    }
    //for (auto it:vec)cout << it << " ";
    if (vec.back() <= 1)cout << "YES" << endl;
    else cout << "NO" << endl;
}