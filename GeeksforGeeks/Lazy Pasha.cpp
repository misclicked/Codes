#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll T;
    cin >> T;
    ll N, Q;
    ll TYP, K;
    while (T--)
    {
        cin >> N >> Q;
        string s;
        cin >> s;
        int offset = 0;
        for (int i = 0; i < Q; i++)
        {
            cin >> TYP >> K;
            if (TYP == 1)
            {
                K %= N;
                offset += (N - K);
                offset %= N;
            }
            else
            {
                cout << s[(offset + K) % N] << endl;
            }
        }
    }
    system("pause");
}