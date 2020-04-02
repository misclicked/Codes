//
// Created by ISMP on 2020/3/25.
//

#pragma GCC optimize("-fopenmp")

#include <bits/stdc++.h>
#include <omp.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MOD 1000000009ll

int dp[1005][1005];


int main() {
    int k, N;
    dp[0][0] = dp[1][1] = dp[2][1] = 1;
    cin >> N >> k;
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= k; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1]) % MOD;
    }
    int ans = 0;
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        std::cout << "Thread number: " << omp_get_thread_num() << endl;

    }
    for (int j = 0; j <= k; j++) {
        ans = (ans + dp[N][j]) % MOD;
    }
    cout << ans - 1 << endl;
}