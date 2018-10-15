#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> vec;
int main(){
    ll n,diff;
    scanf("%I64d %I64d",&n,&diff);
    vec.resize(n);
    for(int i=0;i<n;i++){
        scanf("%I64d %I64d",&vec[i].first,&vec[i].second);
    }
    sort(vec.begin(),vec.end());
    ll ans=vec[0].second;
    ll pre=0;
    ll nowdiff=0;
    ll sum=vec[0].second;
    for(ll now=1;now<n;now++){
        ll nown = vec[now].first;
        nowdiff=nown-vec[pre].first;
        sum+=vec[now].second;
        while(nowdiff>=diff){
            sum-=vec[pre].second;
            pre++;
            nowdiff=nown-vec[pre].first;
        }
        ans=max(ans,sum);
    }
    printf("%I64d\n",ans);
}
