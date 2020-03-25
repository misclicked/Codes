//
// Created by ISMP on 2020/3/25.
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
    string S;
    int T;
    cin >> T;
    unordered_set<string> se;
    stack<string> qe;
    while (T--) {
        int a;
        cin >> a;
        if (a == 1) {
            cin >> S;
            se.insert(S);
            qe.push(S);
        }
        if (a == 2) {
            if (qe.size()) {
                se.erase(qe.top());
                qe.pop();
            }
        }
        if (a == 3) {
            cin >> S;
            if (se.count(S)) {
                cout << "Y";
            } else {
                cout << "N";
            }
        }
    }
    cout << endl;
}