//
// Created by misclicked on 2020/4/13.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

int mp[11][11];
int dir[9][2] = {{0, 0},
                 {1, 4},
                 {2, 8},
                 {3, 1},
                 {4, 5},
                 {5, 6},
                 {6, 2},
                 {7, 3},
                 {8, 7}};

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
    while (T--) {
        string s;
        for (int i = 0; i < 9; i++) {
            cin >> s;
            for (int j = 0; j < 9; j++) {
                mp[i][j] = s[j] - '0';
                mp[i][j]--;
            }
        }
        for (int i = 0; i < 9; i++) {
            mp[dir[i][0]][dir[i][1]] = (mp[dir[i][0]][dir[i][1]] + 1) % 9;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mp[i][j] + 1;
            }
            cout << endl;
        }
    }
}