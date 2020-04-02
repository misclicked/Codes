//
// Created by misclicked on 3/20/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
#define LEFT 1
#define RIGHT 0

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int c;
    int n, t, m;
    cin >> c;
    vector<int> ans;
    priority_queue<pii, vector<pii>, greater<pii> > Lwait, Rwait;
    bool test = false;
    while (c--) {
        cin >> n >> t >> m;
        if (test)cout << endl;
        test = true;
        int T;
        string s;
        ans.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> T >> s;
            if (s == "left")Lwait.push({T, i});
            if (s == "right")Rwait.push({T, i});
        }
        int currentT = 0;
        int currentL = LEFT;
        while (Lwait.size() + Rwait.size()) {
            if (currentL == LEFT) {
                int loaded = 0;
                while (loaded != n && Lwait.size() && Lwait.top().first <= currentT) {
                    loaded++;
                    ans[Lwait.top().second] = currentT + t;
                    Lwait.pop();
                }
                currentT += t;
                currentL ^= 1;
            } else {
                int loaded = 0;
                while (loaded != n && Rwait.size() && Rwait.top().first <= currentT) {
                    loaded++;
                    ans[Rwait.top().second] = currentT + t;
                    Rwait.pop();
                }
                currentT += t;
            }
        }
        for (auto it:ans)cout << it << endl;
    }
}