//
// Created by misclicked on 2/22/20.
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
    int n = 200;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        a.push_back(rand() % 1900);
        b.push_back(rand() % 1900);
    }
    int ansa = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ansa = max(min(a[i] + b[j], a[j] + b[i]), ansa);
        }
    }
    cout << ansa << endl;
    vector<pii> data;
    for (int i = 0; i < n; i++)
        data.push_back({a[i] - b[i], i});
    sort(data.begin(), data.end());
    int best, mex;
    best = 0;
    mex = INT_MIN;
    for (auto it:data) {
        int id = it.second;
        best = max(best, mex + b[id]);
        mex = max(mex, a[id]);
    }
    cout << best << endl;
}