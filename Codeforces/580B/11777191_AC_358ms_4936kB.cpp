#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> vec;
int main(){
    ll n,diff;
    cin>>n>>diff;
    for(int i=0;i<n;i++){
        ll n,d;
        cin>>n>>d;
        vec.push_back(pii(n,d));
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
    cout<<ans<<endl;
}
