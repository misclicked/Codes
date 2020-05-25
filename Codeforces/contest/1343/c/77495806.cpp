//
// Created by misclicked on 2020/4/21.
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
    int T;
    cin >> T;
    vector<ll> vec;
    while (T--) {
        ll n;
        cin >> n;
        vec.resize(n);
        for (auto &it:vec)
            cin >> it;
        bool here = vec[0] < 0;
        ll amax = LLONG_MIN, bmax = LLONG_MIN, ans = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i] < 0) {
                if (here == false) {
                    ans += bmax;
                    //cout << bmax << endl;
                    bmax = LLONG_MIN;
                }
                here = true;
                amax = max(vec[i], amax);
            } else {
                if (here) {
                    ans += amax;
                    //cout << amax << endl;
                    amax = LLONG_MIN;
                }
                here = false;
                bmax = max(vec[i], bmax);
            }
        }
        if (here == false) {
            ans += bmax;
            bmax = 0;
        } else {
            ans += amax;
            amax = 0;
        }
        cout << ans << endl;
    }
}