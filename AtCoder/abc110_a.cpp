#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = -1;
    int a, b, c;
    cin >> a >> b >> c;
    ans = max(ans, a + b * 10 + c);
    ans = max(ans, a + c * 10 + b);
    ans = max(ans, b + a * 10 + c);
    ans = max(ans, b + c * 10 + a);
    ans = max(ans, c + a * 10 + b);
    ans = max(ans, c + b * 10 + a);
    cout << ans << endl;
    //system("pause");
}