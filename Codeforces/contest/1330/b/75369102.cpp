//
// Created by misclicked on 2020/4/3.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
unordered_map<int, int> mpL, mpR;
int mxL[200005];
int mxR[200005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin >> T;
    int n, d;
    vector<int> vec;
    vector<int> ans;
    memset(mxL, 0, sizeof(mxL));
    memset(mxR, 0, sizeof(mxR));
    while (T--) {
        cin >> n;
        vec.clear();
        for (int i = 0; i < n; i++) {
            cin >> d;
            vec.emplace_back(d);
        }
        mpL.clear();
        mpR.clear();
        mxL[0] = mxR[n - 1] = 0;
        mpL[vec[0]] = 1;
        for (int i = 1; i < n; i++)
            mpR[vec[i]]++;
        int szL, szR;
        szL = 1;
        szR = mpR.size();
        for (int i = 1; i < n; i++) {
            mxL[i] = max(mxL[i - 1], vec[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            mxR[i] = max(mxR[i + 1], vec[i + 1]);
        }
        ans.clear();
        for (int i = 1; i < n; i++) {
            if (szL == i && mxL[i] == szL &&
                szR == n - i && mxR[i - 1] == n - i) {
                ans.push_back(i);
            }
            mpR[vec[i]]--;
            mpL[vec[i]]++;
            if (mpR[vec[i]] == 0)szR--;
            if (mpL[vec[i]] == 1)szL++;
        }
        cout << ans.size() << endl;
        for (auto it:ans) {
            cout << it << " " << n - it << endl;
        }
    }
}