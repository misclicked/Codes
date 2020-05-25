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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T, a, b, c, ans;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        ans = 0;
        if (a)a--, ans++;
        if (b)b--, ans++;
        if (c)c--, ans++;
        if (a >= b >= c) {
            if (a && b)a--, b--, ans++;
            if (a && c)a--, c--, ans++;
            if (b && c)b--, c--, ans++;
        } else if (a >= c >= b) {
            if (a && c)a--, c--, ans++;
            if (a && b)a--, b--, ans++;
            if (b && c)b--, c--, ans++;
        } else if (b >= a >= c) {
            if (a && b)a--, b--, ans++;
            if (b && c)b--, c--, ans++;
            if (a && c)a--, c--, ans++;
        } else if (b >= c >= a) {
            if (b && c)b--, c--, ans++;
            if (a && b)a--, b--, ans++;
            if (a && c)a--, c--, ans++;
        } else if (c >= a >= b) {
            if (a && c)a--, c--, ans++;
            if (b && c)b--, c--, ans++;
            if (a && b)a--, b--, ans++;
        } else if (c >= b >= a) {
            if (b && c)b--, c--, ans++;
            if (a && c)a--, c--, ans++;
            if (a && b)a--, b--, ans++;
        } else {
            if (b && c)b--, c--, ans++;
            if (a && c)a--, c--, ans++;
            if (a && b)a--, b--, ans++;
        }
        if (a && b && c)a--, b--, c--, ans++;
        cout << ans << endl;
    }
}