#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
using namespace std;
set<int> fs[35];
bool mape[35][35];
int main()
{
    int n, m;
    cin >> n >> m;
    memset(mape, 0, sizeof(mape));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mape[a][b] = true;
        mape[b][a] = true;
        fs[a].insert(b);
        fs[b].insert(a);
    }
    for (int i = 0; i < n; i++)
    {
        fs[i].insert(i);
    }
    vector<int> vec(35);
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int out = set_intersection(fs[i].begin(), fs[i].end(), fs[j].begin(), fs[j].end(), vec.begin()) - vec.begin();
            // cout << i << " " << j << " " << out << endl;
            bool ok = true;
            for (int ii = 0; ii < out - 1; ii++)
            {
                for (int jj = ii + 1; jj < out; jj++)
                {
                    if (!mape[vec[ii]][vec[jj]])
                        ok = false;
                }
            }
            if (ok)
                ans = max(ans, out);
        }
    }
    cout << ans << endl;
    system("pause");
}