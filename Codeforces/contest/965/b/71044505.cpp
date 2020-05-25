//
// Created by misclicked on 2/14/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

char mape[105][105];
int ans[105][105];
int dirx[2][2] = {
        {0, 1},
        {0, -1},
};
int diry[2][2] = {
        {1,  0},
        {-1, 0}
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n, k, ansx;
    cin >> n >> k;
    memset(mape, '#', sizeof(mape));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mape[i][j];
    for (int i = 1; i <= n; i++) {
        int now = 1;
        while (now <= n) {
            while (mape[i][now] == '#' && now <= n)now++;
            if (now > n)break;
            int st = now;
            while (mape[i][now] == '.')now++;
            cerr << i << " " << st << " " << now << endl;
            for (; st + k <= now; st++) {
                for (int j = st; j < st + k; j++) {
                    ans[i][j]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int now = 1;
        while (now <= n) {
            while (mape[now][i] == '#' && now <= n)now++;
            if (now > n)break;
            int st = now;
            while (mape[now][i] == '.')now++;
            cerr << i << " " << st << " " << now << endl;
            for (; st + k <= now; st++) {
                for (int j = st; j < st + k; j++) {
                    ans[j][i]++;
                }
            }
        }
    }
    int sol = -1, x = 1, y = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] > sol)
                sol = ans[i][j], x = i, y = j;
        }
    }
    cout << x << " " << y << endl;
}