//
// Created by misclicked on 2020/5/24.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifndef OUO
#define cerr if (false) cerr
#endif

int main() {
#ifdef OUO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int t;
    cin >> t;
    int a, b;
    vector<ll> vec;
    while (t--) {
        int n;
        cin >> n;
        a = b = 0;
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            if (vec[i] & 1)a++;
            else b++;
        }
        sort(vec.begin(), vec.end());
        a %= 2;
        b %= 2;
        string ans = "NO";
        if (a && b) {
            for (int i = 1; i < n; i++) {
                if (vec[i] == vec[i - 1] + 1) {
                    ans = "YES";
                }
            }
        } else {
            ans = "YES";
        }
        cout << ans << endl;
    }
}