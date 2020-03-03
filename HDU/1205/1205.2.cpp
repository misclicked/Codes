
#include <bits/stdc++.h>

using namespace std;

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
    int ncases;
    cin >> ncases;

    while (ncases--) {
        long long maxvalue = -1, sweetkinds, sum = 0;
        cin >> sweetkinds;
        long long i, n;
        for (i = 0; i < sweetkinds; i++) {
            cin >> n;
            sum += n;
            if (maxvalue < n)
                maxvalue = n;
        }
        if ((sum - maxvalue) >= (maxvalue - 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}