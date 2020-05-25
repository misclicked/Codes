//
// Created by misclicked on 2020/4/1.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= 10000; i++) {
        bool no = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0)no = true;
        }
        if (!no)primes.push_back(i);
    }
    int ansA, ansB, dis = INT_MAX;
    for (int i = 0; primes[i] <= 1000; i++) {
        if (n % primes[i] == 0) {
            if (abs(n / primes[i] - primes[i]) < dis) {
                dis = abs(n / primes[i] - primes[i]);
                ansA = min(primes[i], n / primes[i]);
                ansB = max(primes[i], n / primes[i]);
            }
        }
    }
    cout << ansA << ansB << endl;
}
