#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll input[100005];
ll sol[100005] = {0};
unordered_map<ll, int> mape;
int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll now = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &sol[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        sol[i] += sol[i - 1];
        sol[i] %= m;
        mape[sol[i]]++;
    }
    ll ans = 0;
    mape[0]++;
    for (auto it : mape)
    {
        ans += it.second * (it.second - 1) / 2;
        //cout << it.first << " " << it.second << endl;
    }
    printf("%lld\n", ans);
}