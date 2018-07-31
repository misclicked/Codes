#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> table;
vector<ll> table2;
#define MAX 2247483647
inline int dig(ll n)
{
    int ret = 0;
    while (n)
    {
        ret++;
        n /= 10;
    }
    return ret;
}
void addDig(ll i)
{
    if (!i)
        return;
    addDig(i / 10);
    table2.push_back(i % 10);
}
void build()
{
    ll now = 1;
    ll nowdig = 0;
    table.push_back(0);
    for (ll i = 0; i <= MAX;)
    {
        nowdig += dig(now);
        i += nowdig;
        now++;
        table.push_back(i);
    }
    //cout << nowdig << endl;
    for (int i = 1; i <= nowdig; i++)
    {
        addDig(i);
        //cout << table2.size() << endl;
    }
}
int main()
{
    build();
    int t;
    cin >> t;
    while (t--)
    {
        ll i;
        cin >> i;
        i--;
        int pos = i - *(upper_bound(table.begin(), table.end(), i) - 1);
        cout << table2[pos] << endl;
    }
}