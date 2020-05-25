//
// Created by misclicked on 4/15/20.
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
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        ll d, mx = LLONG_MIN, ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> d;
            mx = max(mx, d);
            ans = max(ans, mx - d);
        }
        cout << (ans ? floorl(log2l(ans)) + 1 : 0) << endl;
    }
}