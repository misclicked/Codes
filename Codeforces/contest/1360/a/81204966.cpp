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
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        if (a == b)cout << (a * 2) * (a * 2) << endl;
        else {
            if (a < b)swap(a, b);
            if (b * 2 >= a)cout << (b * 2) * (b * 2) << endl;
            else {
                cout << a * a << endl;
            }
        }
    }
}