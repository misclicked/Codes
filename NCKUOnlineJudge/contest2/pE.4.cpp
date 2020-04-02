#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000009;

int fp(ll x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int fac[1005], inv[1005], n, k, ans = 0;

void build()
{
    fac[0] = 1;
    for (ll i = 1; i <= 1001; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    for (ll i = 0; i <= 1001; i++)
        inv[i] = fp(fac[i], MOD - 2);
}

int main()
{
    build();
    scanf("%d%d", &n, &k);
    for (int i = 0; (i << 1) <= n; i++)
        if (k - i >= n - (i << 1))
            ans = (ans + (((ll) fac[i + (n - (i << 1))] * inv[i]) % MOD
                          * inv[n - (i << 1)])) % MOD;
    printf("%d", ans);
}