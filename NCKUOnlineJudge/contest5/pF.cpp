//
// Created by ISMP on 2020/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll ans = 0;

ll gcd(ll a, ll b) {
    if (b == 0)return a;
    ans += (a / b);
    a %= b;
    return gcd(b, a);
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
    ll n, m;
    cin >> n >> m;
    if (m < n)swap(n, m);
    if (n == 1 || n == 2) {
        ans = 0;
        gcd(n, m);
        cout << ans << endl;
    } else if (m - n == 1) {
        if (n % 2 == 0) {
            ll n1 = n / 2, n2 = n - n1;
            ll A, B, C;
            ans = 0;
            gcd(n, m - n / 2);
            ans += 2;
            A = ans;
            ans = 0;
            gcd(n, m);
            C = ans;
            cout << min(A, C) << endl;
        } else {
            ll A, B, C;
            ll m1 = m / 2, m2 = m - m1;
            ans = 0;
            //cout << n << " " << m1 << endl;
            gcd(m, n - m / 2);
            ans += 2;
            B = ans;
            ans = 0;
            gcd(n, m);
            C = ans;
            //cout << B << " " << C << endl;
            cout << min(B, C) << endl;
        }
    } else {
        ans = 0;
        gcd(n, m);
        cout << ans << endl;
    }
}