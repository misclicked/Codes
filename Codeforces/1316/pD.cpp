//
// Created by misclicked on 3/5/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

pii des[1004][1004];
char ans[1004][1004];

int dir[4][2] = {{0,  1},
                 {0,  -1},
                 {1,  0},
                 {-1, 0}};
int symbol[4] = {'R', 'L', 'D', 'U'};

int n;

void mark(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx <= 0 || xx > n || yy <= 0 || yy > n)continue;
        if (des[xx][yy] != (pii) {-1, -1})continue;
        if (ans[xx][yy] != '-') {
            ans[x][y] = symbol[i];
            return;
        } else {
            ans[x][y] = symbol[i];
            ans[xx][yy] = symbol[i ^ 1];
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int x, y;
    cin >> n;
    memset(ans, '-', sizeof(ans));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> x >> y;
            if (x != -1)ans[x][y] = 'X';
            des[i][j] = {x, y};
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == '-' && des[i][j] == (pii) {-1, -1}) {
                mark(i, j);
            }
        }
    }
    for (int i = 1; i <= n)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
}