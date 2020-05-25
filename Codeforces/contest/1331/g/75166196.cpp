//
// Created by misclicked on 2020/4/2.
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
    vector<int> vec;
    for (int i = 0; i < 11; i++) {
        int d;
        cin >> d;
        vec.push_back(d);
    }
    for (int i = 10; i >= 0; i--) {
        int x = vec[i];
        double ans = pow(x, 3) * 5 + sqrt(abs(x));
        if (ans > 400) {
            printf("f(%d) = MAGNA NIMIS!\n",x);
        } else {
            printf("f(%d) = %.2f\n", x, ans);
        }
    }
}