#include <iostream>
#include <cmath>
#define INF 1e9 + 7
#define min(a, b) a > b ? b : a
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            return 0;
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (b >= 0)
                ans = min(ans, ceil((4.5 / a) * 3600.0) + b);
        }
        cout << ans << endl;
    }
}