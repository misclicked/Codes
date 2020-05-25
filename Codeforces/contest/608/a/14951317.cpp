#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll MAX=0;
    typedef pair<ll,ll> p;
    vector<p> vec;
    ll a,b;
    ll n,m;
    cin>>n>>m;
    while(n--){
        cin>>a>>b;
        vec.push_back(p(a,b));
    }
    vec.push_back(p(0,0));
    vec.push_back(p(m,0));
    sort(vec.begin(),vec.end());
    ll ans=0;
    for(int i=vec.size()-1;i>=1;i--){
        if(vec[i].second>ans)
            ans+=vec[i].second-ans;
        ans+=vec[i].first-vec[i-1].first;
    }
    cout<<ans<<endl;
}