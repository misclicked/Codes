#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    s.push_back('#');
    s.push_back('(');
    s.push_back('@');
    for (size_t i = 0; i < s.length() - 3; i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) //aaa => abc
        {
            ans += 2;
            i += 2;
        }
        else if (s[i] == s[i + 1]) //aa => ac
        {
            ans++;
            i++;
        }
        else if (s[i] == s[i + 2])
        {
            ans++;
            if (s[i + 1] != s[i + 3]) //adada => adeca
                i += 2;
        }
    }
    cout << ans << endl;
    system("pause");
}