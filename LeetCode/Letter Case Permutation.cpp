#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<string> vec;
    void solve(string s, int n)
    {
        if (n == s.size())
        {
            vec.push_back(s);
            return;
        }
        if (isalpha(s[n]))
        {
            s[n] = tolower(s[n]);
            solve(s, n + 1);
            s[n] = toupper(s[n]);
            solve(s, n + 1);
        }
        else
        {
            solve(s, n + 1);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        solve(S, 0);
        return vec;
    }
};
int main()
{
    string s = "a1b2";
    vector<string> ans = ((new Solution())->letterCasePermutation(s));
    for (auto it : ans)
    {
        cout << it << endl;
    }
}