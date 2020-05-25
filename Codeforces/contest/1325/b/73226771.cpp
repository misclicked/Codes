//
// Created by misclicked on 2020/3/14.
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
    int t = 0;
    cin >> t;
    unordered_set<int> se;
    while (t--) {
        int n;
        cin >> n;
        int data;
        se.clear();
        for (int i = 0; i < n; i++) {
            cin >> data;
            se.insert(data);
        }
        cout << se.size() << endl;
    }
}