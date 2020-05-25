#include <bits/stdc++.h>
using namespace std;
#define MX 80000000000000000ll
#define MN -80000000000000000ll
#define eps 0.00001
typedef long long ll;
ll mp[105][105],mp2[105][105],t,n,m,ans;

ll eval(ll mid){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll should_be = mid+(i+j)-2;
            if(mp[i][j]<should_be)mp2[i][j]=LLONG_MAX;
            else mp2[i][j]=mp[i][j]-should_be;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1||mp2[i][j]==LLONG_MAX)
                mp2[i][j];
            else if(i==1){
                if(mp2[i][j-1]==LLONG_MAX)
                    mp2[i][j]=LLONG_MAX;
                else
                    mp2[i][j]+=mp2[i][j-1];
            }
            else if(j==1){
                if(mp2[i-1][j]==LLONG_MAX)
                    mp2[i][j]=LLONG_MAX;
                else
                    mp2[i][j]+=mp2[i-1][j];
            }
            else{
                if(mp2[i-1][j]==LLONG_MAX&&mp2[i][j-1]==LLONG_MAX)
                    mp2[i][j]=LLONG_MAX;
                else
                    mp2[i][j]+=min({mp2[i][j-1],mp2[i-1][j]});
            }
        }
    }
    assert(mp2[n][m]>=0);
    ans=min(ans,mp2[n][m]);
    return mp2[n][m];
}

int main() {
    scanf("%I64d",&t);
    vector<ll> vec;
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        vec.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%I64d",&mp[i][j]);
                vec.push_back(mp[i][j]-(i+j-2));
            } 
        }
        ans=LLONG_MAX;
        for(auto it:vec)eval(it);
        printf("%I64d\n",ans);
    }
}
