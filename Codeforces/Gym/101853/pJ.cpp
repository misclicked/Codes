#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mape[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int T;
    cin >> T;
    while (T--)
    {
        memset(mape, 0, sizeof(mape));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            mape[data]++;
        }
        int now = mape[1];
        int ans = mape[1];
        for (int i = 2; i <= 10000; i++)
        {
            now += mape[i];
            ans = max(ans, now);
            now -= mape[i - 1];
        }
        cout << ans << endl;
    }
    //system("pause");
}