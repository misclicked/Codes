#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005][2];
ll input[100005];
ll mape[100005];
int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>input[i];
    }
    for(ll i=0;i<n-1;i++){
        mape[i]=abs(input[i+1]-input[i]);
    }
    if(n==2){
        cout<<mape[0]<<endl;
        return 0;
    }
    ll ans=LLONG_MIN;
    memset(dp,0,sizeof(dp));
    dp[0][0]=mape[0];
    dp[1][0]=mape[1];
    dp[1][1]=max(mape[0]-mape[1],-1*mape[1]);
    ans=max(ans,dp[0][0]);
    ans=max(ans,dp[0][1]);
    ans=max(ans,dp[1][0]);
    ans=max(ans,dp[1][1]);
    for(ll i=2;i<n-1;i++){
        dp[i][0]=max(mape[i],dp[i-1][1]+mape[i]);
        dp[i][1]=max(dp[i-1][0]-mape[i],-1*mape[i]);
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
    }
    cout<<ans<<endl;
}
