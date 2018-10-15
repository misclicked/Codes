#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int T, n, data, ans;
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            if (data)
                ans++;
        }
        cout << ans << endl;
    }
    //system("pause");
};