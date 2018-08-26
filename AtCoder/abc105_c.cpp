#include <bits/stdc++.h>
using namespace std;
string ans;
int input;
void solve(int n)
{
    ans = "";
    while (n)
    {
        if (n % -2)
        {
            n--;
            ans.push_back('1');
        }
        else
            ans.push_back('0');
        n /= -2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
int main()
{
    cin >> input;
    if (!input)
    {
        cout << 0 << endl;
        return 0;
    }
    solve(input);
}