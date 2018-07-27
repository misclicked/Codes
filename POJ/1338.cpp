#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> ugly;
int main()
{
    ugly.push_back(1);
    ll p2, p3, p5;
    p2 = p3 = p5 = 0;
    for (int i = 1; i < 1500; i++)
    {
        ll v2 = ugly[p2] * 2;
        ll v3 = ugly[p3] * 3;
        ll v5 = ugly[p5] * 5;
        ugly.push_back(min(v2, min(v3, v5)));
        if (ugly[i] == v2)
            p2++;
        if (ugly[i] == v3)
            p3++;
        if (ugly[i] == v5)
            p5++;
    }
    int n;
    while (cin >> n)
    {
        if (!n)
            return 0;
        cout << ugly[n - 1] << endl;
    }
}