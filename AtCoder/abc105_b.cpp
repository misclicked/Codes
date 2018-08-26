#include <bits/stdc++.h>
using namespace std;
bool ok;
void dfs(int now)
{
    if (now == 0)
        ok = true;
    if (now < 0 || ok)
        return;
    dfs(now - 4);
    dfs(now - 7);
}
int main()
{
    ok = false;
    int n;
    cin >> n;
    dfs(n);
    cout << (ok ? "Yes" : "No") << endl;
}