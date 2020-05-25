//
// Created by misclicked on 2020/4/13.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<int> mape[30];

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
    while (T--) {
        cin >> n;
        vec.clear();
        for (int i = 1; i <= 26; i++) {
            mape[i].clear();
        }
        for (int i = 0; i < n; i++) {
            cin >> d;
            mape[d].push_back(i);
            vec.push_back(d);
        }
        deque<pii> calc;
        ll ans = 0;
        for (int i = 1; i <= 26; i++) {
            ans = max(ans, (ll) mape[i].size());
        }
        for (int i = 1; i <= 26; i++) {
            for (int j = 1; j <= 26; j++) {
                ll tmp = 0;
                if (i == j)continue;
                calc.clear();
                for (int ii = 0; ii < mape[i].size(); ii++)calc.push_back({mape[i][ii], i});
                for (int jj = 0; jj < mape[j].size(); jj++)calc.push_back({mape[j][jj], j});
                inplace_merge(calc.begin(), calc.begin() + mape[i].size(), calc.end());
                //cout << i << " " << j << endl;
                //for (auto it:calc)cout << it.second << " ";
                //cout << endl;
                //in i out j
                ll outL = 0;
                ll outR = 0;
                ll inSZ = mape[i].size();
                while (calc.size()) {
                    if (outL < outR) {
                        if (calc.front().second == j) {
                            outL++;
                        } else {
                            inSZ--;
                        }
                        calc.pop_front();
                    } else {
                        if (calc.back().second == j) {
                            outR++;
                        } else {
                            inSZ--;
                        }
                        calc.pop_back();
                    }
                    //cout << calc.size() << " " << inSZ << " " << outL << " " << outR << endl;
                    tmp = max(tmp, inSZ + min(outL, outR) * 2);
                }
                //cout << tmp << endl;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
}