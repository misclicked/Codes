//
// Created by misclicked on 2019/10/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9+7ll;
ll ans=1;
ll modpow(ll a, ll b){
    a=a%MOD;
    ll ret=1;
    while(b){
        if(b%2)ret=(ret*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return ret%MOD;
}
inline void calc(const ll n, const ll t){
    ans=((ans*modpow(n,t))%MOD);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll a,b;
    cin>>a>>b;
    vector<ll> pf;
    for(ll i=2;i*i<=a;i++){
        if(a%i==0){
            pf.push_back(i);
            while(a%i==0)a/=i;
        }
    }
    if(a>1)pf.push_back(a);
    ll now,here,cnt;
    for(ll i=0;i<pf.size()&&pf[i]<=b;i++){
        here=pf[i];
        now=here;
        cnt=0;
        ll hehe=b;
        while(hehe){
            cnt+=hehe/=now;
        }
        calc(here,cnt);
    }
    cout<<ans<<endl;
}