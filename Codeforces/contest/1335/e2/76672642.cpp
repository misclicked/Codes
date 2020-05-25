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

vector<int> mape[205];

int T, n, d;
ll ans, outL, outR, inSZ, outSZ, LidxIn, RidxIn, LidxOut, RidxOut;
vector<int> vec;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= 200; i++)
            mape[i].clear();
        for (int i = 0; i < n; i++)
        {
            cin >> d;
            mape[d].emplace_back(i);
        }
        ans = 0;
        for (int i = 1; i <= 200; i++)
            ans = max(ans, (ll) mape[i].size());
        for (int i = 1; i <= 200; i++)
        {
            for (int j = 1; j <= 200; j++)
            {
                if (i == j)continue;
                outL = outR = 0;
                inSZ = mape[i].size();
                outSZ = mape[j].size();
                LidxIn = LidxOut = 0;
                RidxIn = inSZ - 1;
                RidxOut = outSZ - 1;
                if (inSZ + outSZ < ans)continue;
                while (outSZ && inSZ)
                {
                    if (outL < outR)
                    {
                        if (inSZ && (mape[i][LidxIn] < mape[j][LidxOut]))
                            inSZ--, LidxIn++;
                        else
                            outL++, outSZ--, LidxOut++;

                    }
                    else
                    {
                        if (inSZ && mape[i][RidxIn] > mape[j][RidxOut])
                            inSZ--, RidxIn--;
                        else
                            outR++, outSZ--, RidxOut--;
                    }
                    ans = max(ans, inSZ + min(outL, outR) * 2);
                }
            }
        }
        cout << ans << endl;
    }
}