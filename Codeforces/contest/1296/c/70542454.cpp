//
// Created by misclicked on 2/6/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

unordered_map<ll, int> mape;

ll Hash(int x, int y) {
    return x * 200005ll + y;
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        mape.clear();
        int nowx{0}, nowy{0}, step{1};
        mape[Hash(nowx, nowy)] = step;
        int ans = INT_MAX;
        int ansl, ansr;
        for (char ch:s) {
            switch (ch) {
                case 'L': {
                    nowx--;
                    break;
                }
                case 'R': {
                    nowx++;
                    break;
                }
                case 'U': {
                    nowy++;
                    break;
                }
                case 'D': {
                    nowy--;
                    break;
                }
            }
            cerr << step << " " << mape[Hash(nowx, nowy)] << endl;
            cerr << "now " << nowx << " " << nowy << endl;
            int here = mape[Hash(nowx, nowy)];
            if (here && step - here < ans) {
                ans = step - here;
                ansl = here;
                ansr = step;
            }
            mape[Hash(nowx, nowy)] = ++step;
        }
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ansl << " " << ansr << endl;
    }
}