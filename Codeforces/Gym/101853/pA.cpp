#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> mape;
ll SZ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    ll T;
    cin >> T;
    vector<ll> vec;
    while (T--)
    {
        ll n, q;
        cin >> n >> q;
        vec.clear();
        mape.clear();
        ll data;
        SZ = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            vec.push_back(data);
            if (data != 0)
            {
                if (mape[data] == 0)
                    SZ++;
                mape[data]++;
            }
        }
        ll cmd, p, v;
        for (int i = 0; i < q; i++)
        {
            cin >> cmd;
            if (cmd == 1)
            {
                cin >> p >> v;
                if (v != vec[p - 1])
                {
                    if (vec[p - 1] != 0)
                    {
                        mape[vec[p - 1]]--;
                        if (mape[vec[p - 1]] == 0)
                        {
                            SZ--;
                        }
                    }
                    if (v != 0)
                    {
                        if (mape[v] == 0)
                            SZ++;
                        mape[v]++;
                    }
                    vec[p - 1] = v;
                }
            }
            else
            {
                cout << SZ << endl;
            }
        }
    }
    //system("pause");
};