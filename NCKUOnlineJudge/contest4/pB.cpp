//
// Created by ISMP on 2020/4/22.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<int> primes{2, 3, 5, 7};

ll lst[15] = {0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (auto it:primes) {
        ll cnt = 0;
        while (n % it == 0) {
            n /= it;
            cnt++;
        }
        lst[it] += cnt;
    }
    if (n > 1)cout << -1 << endl;
    else {
        lst[8] = lst[2] / 3;
        lst[2] %= 3;
        lst[4] = lst[2] / 2;
        lst[2] %= 2;
        lst[9] = lst[3] / 2;
        lst[3] %= 2;
        if (lst[3] && lst[2]) {
            if (lst[3] > lst[2]) {
                lst[6] = lst[2];
                lst[3] -= lst[2];
                lst[2] = 0;
            } else {
                lst[6] = lst[3];
                lst[2] -= lst[3];
                lst[3] = 0;
            }
        }
        for (int i = 2; i <= 9; i++) {
            for (int j = 0; j < lst[i]; j++)
                cout << i;
        }
        cout << endl;
    }
}