//
// Created by misclicked on 3/3/20.
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
    int n, m;
    cin >> n >> m;
    vector<string> vec;
    string s;
    map<string, int> mape;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vec.push_back(s);
        mape[s]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s = "";
            for (int k = 0; k < m; k++) {
                if (vec[i][k] == vec[j][k])s.push_back(vec[i][k]);
                if (vec[i][k] == 'S' && vec[j][k] == 'E' ||
                    vec[i][k] == 'E' && vec[j][k] == 'S')
                    s.push_back('T');
                if (vec[i][k] == 'S' && vec[j][k] == 'T' ||
                    vec[i][k] == 'T' && vec[j][k] == 'S')
                    s.push_back('E');
                if (vec[i][k] == 'T' && vec[j][k] == 'E' ||
                    vec[i][k] == 'E' && vec[j][k] == 'T')
                    s.push_back('S');
            }
            ans += mape[s];
        }
    }
    cout << ans / 3 << endl;
}