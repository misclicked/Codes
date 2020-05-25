//
// Created by misclicked on 4/8/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

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
    vector<int> a, b, c;
    while (T--)
    {
        int n;
        cin >> n;
        a.resize(n);
        b.resize(n);
        c.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1] == -1)
                c[i] = c[i - 1] | 1;
            if (a[i - 1] == 0)
                c[i] = c[i - 1] | 2;
            if (a[i - 1] == 1)
                c[i] = c[i - 1] | 4;
        }
        string ans = "YES";
        for (int i = 0; i < n; i++)
        {
            if (b[i] > a[i])
            {
                if ((c[i] & 4) != 4)ans = "NO";
            }
            if (b[i] < a[i])
            {
                if ((c[i] & 1) != 1)ans = "NO";
            }
        }
        cout << ans << endl;
    }
}