//
// Created by misclicked on 3/3/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
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
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y, d, mm, dd;
    cin >> y >> d >> mm >> dd;
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0)
                month[2]++;
        } else {
            month[2]++;
        }
    }
    cerr << month[2] << endl;
    if (mm > 12 || mm < 1) {
        cout << -1 << endl;
        return 0;
    }
    if (dd > month[mm] || dd < 1) {
        cout << -2 << endl;
        return 0;
    }
    int days{dd};
    for (int i = 1; i < mm; i++) {
        days += month[i];
    }
    cerr << days << endl;
    cout << (days + d - 1) % 7 << endl;
}