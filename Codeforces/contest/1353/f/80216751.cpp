#include <bits/stdc++.h>
using namespace std;
#define MX 80000000000000000ll
#define MN -80000000000000000ll
#define eps 0.00001
typedef long long ll;
ll mp[105][105],dp[105][105],t,n,m,ans;

ll eval(ll mid){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            ll should_be = mid+(i+j)-2;
            if(mp[i][j]<should_be)dp[i][j]=LLONG_MAX;
            else dp[i][j]=mp[i][j]-should_be;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(i==1&&j==1||dp[i][j]==LLONG_MAX)
                dp[i][j];
            else if(i==1){
                if(dp[i][j-1]==LLONG_MAX)
                    dp[i][j]=LLONG_MAX;
                else
                    dp[i][j]+=dp[i][j-1];
            }
            else if(j==1){
                if(dp[i-1][j]==LLONG_MAX)
                    dp[i][j]=LLONG_MAX;
                else
                    dp[i][j]+=dp[i-1][j];
            }
            else{
                if(dp[i-1][j]==LLONG_MAX&&dp[i][j-1]==LLONG_MAX)
                    dp[i][j]=LLONG_MAX;
                else
                    dp[i][j]+=min({dp[i][j-1],dp[i-1][j]});
            }
        }
    }
    ans=min(ans,dp[n][m]);
    return dp[n][m];
}

int main() {
    cin>>t;
    vector<ll> vec;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>mp[i][j];
                vec.push_back(mp[i][j]-(i+j-2));
            } 
        }
        ans=LLONG_MAX;
        for(auto it:vec)eval(it);
        cout<<ans<<endl;
    }
}