//
// Created by misclicked on 2020/4/13.
//

#pragma GCC optimization ("unroll-loops")`
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<int> mape[205];

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
        for (int i = 1; i <= 200; i++) {
            mape[i].clear();
        }
        for (int i = 0; i < n; i++) {
            cin >> d;
            mape[d].push_back(i);
            vec.push_back(d);
        }
        ll ans = 0;
        for (int i = 1; i <= 200; i++) {
            ans = max(ans, (ll) mape[i].size());
        }
        for (int i = 1; i <= 200; i++) {
            for (int j = 1; j <= 200; j++) {
                ll tmp = 0;
                if (i == j)continue;
                ll outL = 0;
                ll outR = 0;
                ll inSZ = mape[i].size();
                int LidxIn = 0;
                int RidxIn = mape[i].size() - 1;
                int LidxOut = 0;
                int RidxOut = mape[j].size() - 1;
                //cout << "Start:" << i << " " << j << endl;
                while (outL + outR < mape[j].size() && inSZ) {
                    if (outL < outR) {
                        if (inSZ && (mape[i][LidxIn] < mape[j][LidxOut])) {
                            inSZ--;
                            LidxIn++;
                        } else {
                            outL++;
                            LidxOut++;
                        }
                    } else {
                        if (inSZ && mape[i][RidxIn] > mape[j][RidxOut]) {
                            inSZ--;
                            RidxIn--;
                        } else {
                            outR++;
                            RidxOut--;
                        }
                    }
                    //cout << outL << " " << outR << " " << inSZ << endl;
                    //cout << mape[i][LidxIn] << " " << mape[i][RidxIn] << endl;
                    //cout << mape[j][RidxIn] << " " << mape[j][RidxOut] << endl;
                    tmp = max(tmp, inSZ + min(outL, outR) * 2);
                }
                //cout << tmp << endl;
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
}