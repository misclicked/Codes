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
    vector<int> vec;
    map<vector<int>, int> mape;
    while (T--) {
        cin >> a >> b >> c;
        a = min(a, 4);
        b = min(b, 4);
        c = min(c, 4);
        vec.clear();
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        sort(vec.begin(), vec.end());
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
            if (b >= c >= a) {
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

            if (a && c)a--, c--, ans++;
        } else if (a && b && c)a--, b--, c--, ans++;
        mape[vec] = ans;
        cout << ans << endl;
    }
    for (auto it:mape) {
        string s;
        for (auto it2:it.first) {
            s.push_back('0' + it2);
        }
        for (auto it2:s)
            cout << it2 << " ";
        cout << endl;
    }
}