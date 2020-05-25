#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int prv, now, ans = 0;
    int ANS = 0;
    bool flag = false;
    cin >> prv;
    for (int i = 1; i < n; i++)
    {
        cin >> now;
        if (now == prv + 1)
        {
            flag = true;
            ans++;
        }
        else if (flag)
        {
            if (i == prv && ans == i - 1)
                ans++;
            flag = false;
            ans--;
            ANS = max(ans, ANS);
            ans = 0;
        }
        prv = now;
    }
    if (flag)
    {
        if (prv == n)
            ans++;
        if (prv == 1000)
            ans++;
        flag = false;
        ans--;
        ANS = max(ans, ANS);
        ans = 0;
    }
    cout << ANS << endl;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}