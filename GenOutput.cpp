//
// Created by misclicked on 2019/8/17.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool vis[1005] = {0};
vector<int> G[1005];

void DFS(int v) {
    vis[v] = true;
    for (auto it:G[v]) {
        if (!vis[it])DFS(it);
    }
}

int main() {
    srand(time(0));
    freopen("input.txt", "w", stdout);
    int T = 5000;
    cout << T << endl;
    while (T--) {
        int n, c, now;
        n = rand() % 10 + 2;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << rand() % 10 << " ";
        }
        cout << endl;
    }
}