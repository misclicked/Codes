//
// Created by misclicked on 2020/3/9.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
int n;
vector<int> vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vec.resize(n);
        for (int i = 0; i < n; i++)cin >> vec[i];
        sort(vec.begin(), vec.end(), greater<int>());
        cout << vec[0];
        for (int i = 1; i < n; i++)cout << " " << vec[i];
        cout << endl;
    }
}