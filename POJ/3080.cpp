#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        vector<string> vec(m);
        for (int i = 0; i < m; i++)
        {
            cin >> vec[i];
        }
        vector<string> ans;
        string out = "no significant commonalities";
        for (int i = 3; i <= 60; i++) //vec[0] length: i
        {
            bool okall = true;
            for (int j = 0; j <= 60 - i; j++)
            { //vec[0] start: j
                okall = true;
                for (int k = 1; k < m; k++)
                { //to compare: vec[k]
                    bool ok = true;
                    for (int s = 0; s <= 60 - i; s++)
                    { //vec[k] start: s
                        ok = true;
                        for (int f = 0; f < i; f++)
                        { //now compare: vec[k][s+f]
                            if (vec[k][s + f] != vec[0][j + f])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (ok)
                            break;
                    }
                    if (!ok)
                    {
                        okall = false;
                        break;
                    }
                }
                if (okall)
                {
                    ans.push_back(vec[0].substr(j, i));
                }
            }
            if (ans.size())
            {
                sort(ans.begin(), ans.end());
                out = ans[0];
            }
            ans.clear();
        }
        cout << out << endl;
    }
    system("pause");
}