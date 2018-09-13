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
        int n;
        cin >> n;
        if (n <= 3)
            cout << 1 << endl;
        else
            cout << ceil((n - 1) / 2.0) << endl;
    }
}