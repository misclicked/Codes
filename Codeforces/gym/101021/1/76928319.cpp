//
// Created by misclicked on 4/16/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

#define ALL(x) (x).begin(),(x).end()
#define OUT(x) for(int _i=0;_i<(x).size();_i++)cout<<(x)[_i]<<" ";
int mp[200005][256];

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
    int T;
    cin >> T;
    while (T--)
    {
        int k, n;
        string s;
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++)memset(mp[i], 0, sizeof(mp[i]));
        //for (int i = 0; i < n; i += k)
        //{
        //    for (int j = 0; j < k; j++)
        //    {
        //        cout << s[i + j];
        //    }
        //    cout << endl;
        //}
        for (int i = 0; i < n; i++)
        {
            mp[i % k][s[i]]++;
        }
        int L = 0, R = k - 1;
        ll ans = 0;
        ll batch = n / k << 1;
        //cout << batch << endl;
        while (L <= R)
        {
            int mx = 0;
            char winner;
            for (int i = 'a'; i <= 'z'; i++)
            {
                if (mp[L][i] + mp[R][i] > mx)
                {
                    winner = i;
                    mx = mp[L][i] + mp[R][i];
                }
            }
            if (L == R)ans += batch / 2 - mx / 2;
            else ans += batch - mx;
            //cout << winner << " " << mx << endl;
            L++;
            R--;
        }
        //cout << endl;
        cout << ans << endl;
    }
}