//
// Created by misclicked on 3/30/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ll t, n, a, b, c, d, ansA, ansB;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld", &n, &a, &b);
        if (a < b)swap(a, b);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &d);
            if ((d % a) % c == 0 || (d % b) % c == 0)ansA++;
            else ansB++;
        }
        printf("%lld %lld\n", ansA, ansB);
    }
}