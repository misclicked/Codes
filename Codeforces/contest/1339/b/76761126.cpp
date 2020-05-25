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
    int T;
    cin >> T;
    vector<int> vec;
    while (T--)
    {
        vec.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int d;
            cin >> d;
            vec.push_back(d);
        }
        sort(ALL(vec));
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                ans.push_back(vec[n - 1 - (i >> 1)]);
            }
            else
            {
                ans.push_back(vec[i >> 1]);
            }
        }
        reverse(ALL(ans));
        OUT(ans);
        cout << endl;
    }
}