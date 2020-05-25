//
// Created by misclicked on 2020/4/13.
//
#pragma GCC option("arch=native","tune=native","no-zero-upper","D_GLIBCXX_PARALLEL","openmp")
#pragma gcc optimize("Ofast")
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
#endif
    int T;
    scanf("%d", &T);
    int n, d;
    vector<int> vec;
    ll ans = 0;
    while (T--) {
        scanf("%d", &n);
        #pragma omp parallel for
        for (int i = 1; i <= 200; i++) {
            mape[i].clear();
        }
        #pragma omp parallel for
        for (int i = 0; i < n; i++) {
            scanf("%d", &d);
            mape[d].push_back(i);
        }
        ans = 0;
        #pragma omp parallel for
        for (int i = 1; i <= 200; i++) {
            ans = max(ans, (ll) mape[i].size());
        }
        for (int i = 1; i <= 200; i++) {
            #pragma omp parallel for
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
                ll outSZ = mape[j].size();
                while (outL + outR < outSZ && inSZ) {
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
                    tmp = max(tmp, inSZ + min(outL, outR) * 2);
                }
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
}