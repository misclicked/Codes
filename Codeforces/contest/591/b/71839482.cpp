//
// Created by misclicked on 2/25/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

char mape[256];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> vec[256];
    for (char c = 'a'; c <= 'z'; c++)vec[c].push_back(c);
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        swap(vec[a], vec[b]);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (auto it:vec[c]) {
            mape[it] = c;
        }
    }
    for (auto it:s) {
        cout << mape[it];
    }
    cout << endl;
}