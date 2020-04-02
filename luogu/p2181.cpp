//
// Created by misclicked on 4/1/20.
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
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n - 3; i++)
    {
        cout << (max(n - 2 - i, i)) * n << endl;
        ans += (max(n - 2 - i, i)) * n;
    }
    cout << (ans >> 1) << endl;
}