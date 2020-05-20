//
// Created by ISMP on 2020/4/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif


int cnt[105];

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
    int d;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cin >> d;
        cnt[d]++;
    }
    for (int i = 100; i >= 1; i--) {
        for (int j = 0; j < cnt[i]; j++)
            cout << i << " ";
    }
    cout << endl;
}