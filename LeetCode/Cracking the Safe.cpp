#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int n, k;
    int len = 0;
    string ans;
    unordered_set<string> visited;
    bool dfs()
    {
        if (ans.length() == len)
            return true;
        string now = ans.substr(ans.length() - n + 1, n - 1);
        for (char c = '0'; c < '0' + k; c++)
        {
            now.push_back(c);
            if (!visited.count(now))
            {
                ans.push_back(c);
                visited.insert(now);
                if (dfs())
                    return true;
                visited.erase(now);
                ans.pop_back();
            }
            now.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k)
    {
        this->n = n;
        this->k = k;
        len = pow(k, n) + n - 1;
        for (int i = 0; i < n; i++)
            ans.push_back('0');
        visited.insert(ans);
        dfs();
        return ans;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    cout << (new Solution())->crackSafe(n, k) << endl;
}