//
// Created by ISMP on 2020/3/25.
//
//#include "lib0020.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int is_broken(long long k) {
    return k > 95;
}

long long height_limit(long long M) {
    long long int L = 0, R = M, mid, ans = 0;
    while (L <= R) {
        mid = (L + R) >> 1;
        if (is_broken(mid)) {
            R = mid - 1;
        } else {
            L = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cout << height_limit(800) << endl;
}