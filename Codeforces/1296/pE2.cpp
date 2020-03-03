//
// Created by misclicked on 2/18/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
#define MAX_N 200005

ll dp[MAX_N] = {0};
ll ans[MAX_N] = {0};

int lower_bit(int n) {
    return n & -n;
}

ll Gmax(int n) {
    ll s = 0;
    while (n > 0) {
        s = max(s, dp[n]);
        n -= lower_bit(n);
    }
    return s;
}

void update(int n, ll d) {
    while (n < MAX_N) {
        dp[n] = max(d, dp[n]);
        n += lower_bit(n);
    }
}

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

vector<pci> vec;

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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        vec.push_back({s[i], i});
    }
    stable_sort(vec.begin(), vec.end());
    for (auto it:vec) {
        cerr << it.first << " " << it.second << endl;
    }
    ll MAXE = 0;
    dp[1] = 0;
    for (int i = 0; i < n; i++) {
        ll now = Gmax(n - vec[i].second) + 1;
        cerr << "update " << n - vec[i].second + 1 << " = " << now << endl;
        ans[vec[i].second] = now;
        MAXE = max(MAXE, now);
        update(n - vec[i].second + 1, now);
        /*for (int j = 1; j <= n + 1; j++) {
            cerr << dp[j] << " ";
        }
        cerr << endl;*/
    }
    cout << MAXE << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}