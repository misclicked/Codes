//
// Created by ISMP on 2020/3/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE
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
    vector<string> vec;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    string s;
    ll ans = 0;
    do {
        s = vec[0] + vec[1] + vec[2];
        ans = max(ans, stoll(s));
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans << endl;
}