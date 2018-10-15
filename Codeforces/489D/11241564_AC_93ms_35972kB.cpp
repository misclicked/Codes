#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int mape[3005][3005]={0};
vector<int> in[3005],out[3005];
int main(){
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        out[a].push_back(b);
        in[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<in[i].size();j++)
            for(int k=0;k<out[i].size();k++)
                mape[in[i][j]][out[i][k]]++;
    }
    ll ans=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            ans+=(mape[i][j]*(mape[i][j]-1))/2;
            ans+=(mape[j][i]*(mape[j][i]-1))/2;
        }
    printf("%I64d\n",ans);
}
