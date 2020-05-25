//
// Created by misclicked on 3/7/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<ll, ll> mape;

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
    ll n, m, k;
    vector<int> a, b;
    cin >> n >> m >> k;
    int now = 0;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (data == 1) {
            now++;
        } else {
            if (now) {
                a.push_back(now);
                now = 0;
            }
        }
    }
    if (now) {
        a.push_back(now);
        now = 0;
    }
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        if (data == 1) {
            now++;
        } else {
            if (now) {
                b.push_back(now);
                now = 0;
            }
        }
    }
    if (now) {
        b.push_back(now);
        now = 0;
    }
    vector<pii> vec;
    for (int i = 1; (i * i) <= k; i++) {
        if (k % i == 0) {
            vec.push_back({i, k / i});
            if (i * i != k) {
                vec.push_back({k / i, i});
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k < vec.size(); k++) {
        ll ft = 0;
        for (int i = 0; i < a.size(); i++) {
            if (vec[k].first <= a[i]) {
                ft += (a[i] - vec[k].first + 1);
            }
        }
        for (int j = 0; j < b.size(); j++) {
            if (vec[k].second <= b[j]) {
                ans += ft * (b[j] - vec[k].second + 1);
            }

        }
    }
    cout << ans << endl;
}