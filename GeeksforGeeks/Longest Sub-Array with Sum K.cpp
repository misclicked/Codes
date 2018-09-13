#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int data;
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            sum += data;
            if (sum == k)
                ans = i + 1;

            if (!um.count(sum))
                um[sum] = i;

            if (um.count(sum - k))
            {
                ans = max(ans, i - um[sum - k]);
            }
        }
        cout << ans << endl;
    }
    system("pause");
}