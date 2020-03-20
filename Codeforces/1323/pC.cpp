//
// Created by misclicked on 3/7/20.
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int L, R;
    L = R = 0;
    for (auto it:s) {
        if (it == '(')L++;
        else R++;
    }
    if (L != R) {
        cout << -1 << endl;
        return 0;
    }
    L = R = 0;
    stack<char> sta;
    ll ans = 0;
    bool dontdoit = false;
    for (int i = 0; i < n; i++) {
        dontdoit = false;
        if (s[i] == '(') {
            L++;
            if (L == R) {
                cerr << L << " " << R << endl;
                cerr << sta.size() << endl;
                if (!sta.empty()) {
                    ans += L + R;
                    dontdoit = true;
                    while (sta.size())sta.pop();
                }
                L = R = 0;
            }
        } else {
            R++;
            if (sta.size() && sta.top() == '(') {
                cerr << "POP:(" << endl;
                dontdoit = true;
                sta.pop();
            }
            if (L == R) {
                cerr << L << " " << R << endl;
                cerr << sta.size() << endl;
                if (!sta.empty()) {
                    ans += L + R;
                    dontdoit = true;
                    while (sta.size())sta.pop();
                }
                L = R = 0;
            }
        }
        if (!dontdoit) {

            cerr << "PUSH:" << s[i] << endl;
            sta.push(s[i]);
        }
    }
    cout << ans << endl;
}