#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
    int n;
    cin >> n;
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }
    vec.push_back(1001);
    int ans = 0;
    for (int a = 1; a <= n; a++)
    {
        for (int b = a; b <= n; b++)
        {
            int tmp = 0;
            //cout << a << " " << b << endl;
            for (int i = a; i <= b; i++)
            {
                if (vec[i] == vec[i - 1] + 1)
                {
                    tmp++;
                }
                else
                {
                    tmp = 0;
                    break;
                }
            }
            if (tmp && vec[b + 1] == vec[b] + 1)
            {
                //cout << tmp << endl;
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}