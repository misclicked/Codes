//
// Created by ISMP on 2020/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
int n, i, j;
char A[3005];
char B[3005];
vector<short> C;

vector<short> dp[256];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    //ios_base::sync_with_stdio(false);
    //cin.tie();
#endif
    int n;
    cin >> n;
    scanf("%d", &n);
    scanf("%s", A);
    scanf("%s", B);
    for (int i = n - 1; i >= 0; i--) {
        dp[B[i]].push_back(i);
    }
    vector<short> ans;
    for (int i = 0; i < n; i++) {
        for (auto it:dp[A[i]]) {
            if (ans.empty())ans.push_back(it);
            else if (it > ans.back()) ans.push_back(it);
            else *lower_bound(ans.begin(), ans.end(), it) = it;
        }
    }
    cout << ans.size() << endl;
}