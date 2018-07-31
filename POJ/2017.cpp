#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> mile, hr;
    while (cin >> n)
    {
        if (n == -1)
            return 0;
        mile.clear();
        hr.clear();
        mile.push_back(0);
        hr.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            mile.push_back(a);
            hr.push_back(b);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += (hr[i] - hr[i - 1]) * mile[i];
        }
        cout << ans << " miles" << endl;
    }
}