//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dp[1005][1005];
int mape[1005][1005];
#define MOD 998244353

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    memset(mape,0,sizeof(mape));
    memset(dp,-1,sizeof(dp));
    int n,k,r;
    cin>>n>>k>>r;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        mape[a][b]=1;
        dp[a][b]=-1;
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1)continue;
            if(!mape[i][j]){
                if(dp[i-1][j]==-1&&dp[i][j-1]==-1){
                    dp[i][j]=-1;
                }else if(dp[i-1][j]==-1){
                    dp[i][j]=dp[i][j-1];
                }else if(dp[i][j-1]==-1){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                }
            }
        }
    }
    while(r--){
        int a,b;
        cin>>a>>b;
        if(dp[a][b]==-1)
            cout<<0<<endl;
        else
            cout<<dp[a][b]%MOD<<endl;
    }
}
