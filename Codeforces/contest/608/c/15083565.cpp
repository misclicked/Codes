#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pir;
ll dp[1000005];
ll input[1000005];
int main(){
    ll n;
    cin>>n;
    ll nn=n;
    map<ll,ll> mape;
    ll maxn=0;
    ll data1,data2;
    memset(input,0,sizeof(input));
    memset(dp,0,sizeof(dp));
    while(n--){
        cin>>data1>>data2;
        input[data1]=data2;
        maxn=max(data1,maxn);
    }
    for(int i=0;i<=1000000;i++){
        if(!input[i])
            dp[i]=dp[i-1];
        else if(i-input[i]>=0)
            dp[i]=dp[i-input[i]-1]+1;
        else
            dp[i]=1;
    }
    ll ans=0;
    for(int i=0;i<=1000000;i++)
        ans=max(ans,dp[i]);
    cout<<nn-ans<<endl;
}