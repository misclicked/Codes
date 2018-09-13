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
        unordered_map<char, int> um;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (!um.count(s[i]))
            {
                um[s[i]] = i;
            }
        }
        cin >> s;
        int ans = INT_MAX;
        char ansc = '@';
        for (int i = 0; i < s.size(); i++)
        {
            if (um.count(s[i]))
            {
                if (um[s[i]] < ans)
                {
                    ans = um[s[i]];
                    ansc = s[i];
                }
            }
        }
        if (ansc == '@')
        {
            cout << "No character present" << endl;
        }
        else
        {
            cout << ansc << endl;
        }
    }
    system("pause");
}