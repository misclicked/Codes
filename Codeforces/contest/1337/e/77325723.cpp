#import<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
string s,t;
ll dp[3002][3002],n,m,ans=0,i,l,r;
int main(){
    cin>>s>>t;
    n=s.size();m=t.size();
    s="*"+s;t="*"+t;
    for(i=1;i<=n+1;++i)dp[i][i-1]=1;
    for(i=1;i<=n;++i)
    for(l=1,r=l+i-1;r<=n;++l,++r){
        if(l>m||s[i]==t[l])dp[l][r]+=dp[l+1][r]%mod;
        if(r>m||s[i]==t[r])dp[l][r]+=dp[l][r-1]%mod;
    }
    for(i=m;i<=n;++i)
    ans=(ans+dp[1][i])%mod;
    cout<<ans;
}