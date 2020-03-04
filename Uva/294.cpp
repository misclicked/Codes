//
// Created by misclicked on 3/4/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
vector<ll> primes;
int np[50005] = {1, 1};

void build() {
    for (int i = 2; i * i <= 1000000000; i++) {
        if (np[i] == 0)primes.push_back(i);
        for (int j = 0; (i * primes[j] * i * primes[j]) <= 1000000000; j++) {
            np[i * primes[j]] = 1;
            if (i % primes[j] == 0)break;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    build();
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        ll mx, ans;
        mx = 0;
        for (ll i = a; i <= b; i++) {
            ll now = 1;
            ll k = i;
            for (int j = 0; (primes[j] * primes[j]) <= k && j < primes.size(); j++) {
                int here = 0;
                while (k % primes[j] == 0) {
                    k /= primes[j];
                    here++;
                }
                now *= here + 1;
            }
            if (k != 1)now *= 2;
            if (mx < now) {
                mx = now, ans = i;
            }
        }
        cout << "Between " << a << " and " << b <<
             ", " << ans << " has a maximum of " << mx << " divisors." << endl;
    }
}