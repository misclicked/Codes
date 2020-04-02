//
// Created by misclicked on 3/24/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

//#define ONLINE_JUDGE
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
    int T, n;
    unordered_map<ll, ll> mape;
    vector<ll> vec;
    cin >> T;
    int cnt = 1;
    while (T--) {
        cin >> n;
        mape.clear();
        vec.clear();
        for (int i = 0; i < n; i++) {
            ll data;
            cin >> data;
            vec.push_back(data);
            mape[data]++;
        }
        ll ans = 0;
        ll special = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)continue;
                if (!(vec[i] && vec[j]))continue;
                ll now = 0;
                ll matched = mape[vec[i] * vec[j]];
                if ((vec[i] * vec[j]) == vec[i])matched--;
                if ((vec[i] * vec[j]) == vec[j])matched--;
                now += matched;
                if (vec[i] % vec[j] == 0) {
                    matched = mape[vec[i] / vec[j]];
                    if ((vec[i] / vec[j]) == vec[i])matched--;
                    if ((vec[i] / vec[j]) == vec[j])matched--;
                    now += matched;
                }
                if (vec[j] % vec[i] == 0) {
                    matched = mape[vec[j] / vec[i]];
                    if ((vec[j] / vec[i]) == vec[i])matched--;
                    if ((vec[j] / vec[i]) == vec[j])matched--;
                    now += matched;
                }
                if (vec[i] == 1 && vec[j] == 1) {
                    now /= 3;
                }
                ans += now;
            }
        }
        ll ans2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (vec[i] * vec[j] == vec[k] ||
                        vec[i] * vec[k] == vec[j] ||
                        vec[j] * vec[k] == vec[i]) {
                        ans2++;
                        cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
        cout << "Case #" << cnt << ": " << ans2 << endl;
        cout << "Case #" << cnt++ << ": " << ans / 6 << endl;
    }
}