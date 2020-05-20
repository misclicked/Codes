#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[105][105];

void build() {
    for (int i = 1; i <= 100; i++)dp[i][i] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j++) {
            dp[i][j] = dp[i][i] + dp[i][j - i];
        }
    }
}

int main() {
    build();
    int n, m;
    cin >> n >> m;
    cout << dp[n][m] << endl;
}