//
// Created by misclicked on 3/7/20.
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
    string s;
    deque<char> vec;
    int state = 0;
    cin >> s;
    for (auto it:s)vec.push_back(it);
    int a, b;
    char c;
    int q;
    cin >> q;
    while (q--) {
        cin >> a;
        if (a == 1)state ^= 1;
        else {
            cin >> b >> c;
            if (b == 1) {
                if (!state) {
                    vec.push_front(c);
                } else {
                    vec.push_back(c);
                }
            } else {
                if (!state) {
                    vec.push_back(c);
                } else {
                    vec.push_front(c);
                }
            }
        }
    }
    if (state)reverse(vec.begin(), vec.end());
    for (auto it:vec)
        cout << it;
    cout << endl;
}