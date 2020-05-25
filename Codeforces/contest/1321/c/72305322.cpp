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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx, id;
    while (true) {
        mx = -1, id = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] - s[i + 1] == 1) {
                if (s[i] > mx) {
                    mx = s[i];
                    id = i;
                }
            }
            if (s[i + 1] - s[i] == 1) {
                if (s[i + 1] > mx) {
                    mx = s[i + 1];
                    id = i + 1;
                }
            }
        }
        cerr << s << " " << (char) mx << endl;
        if (mx == -1)break;
        s = s.substr(0, id) + s.substr(id + 1);
    }
    cout << n - s.size() << endl;
}