#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> vec[100005];
LL deg[100005];
LL dp[100005];
int main(){
    LL n,m,a,b;
    cin>>n>>m;
    memset(deg,0,sizeof(deg));
    for(LL i=0;i<m;i++){
        cin>>a>>b;
        if(a<b)
            vec[b].push_back(a);
        else
            vec[a].push_back(b);
        deg[a]++;
        deg[b]++;
    }
    for(LL i=1;i<=n;i++){
        dp[i]=1;
    }
    LL ans=0;
    for(LL i=1;i<=n;i++){
        for(LL j=0;j<vec[i].size();j++){
            dp[i]=max(dp[i],1+dp[vec[i][j]]);
        }
        ans=max(ans,dp[i]*deg[i]);
    }
    cout<<ans<<endl;
}