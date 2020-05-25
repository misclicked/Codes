//
// Created by misclicked on 2019/6/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    vector<ll> veca,vecb;
    int data;
    veca.resize(n);
    vecb.resize(m);
    for(auto &it:veca)
        cin>>it;
    for(auto &it:vecb)
        cin>>it;
    if(k>=m||k>=n){
        cout<<-1<<endl;
        return 0;
    }
    ll crit=0;
    for(int i=0;i<n;i++){
        if(lower_bound(vecb.begin(),vecb.end(),veca[i]+ta)!=vecb.end()){
            crit=i;
            break;
        }
    }
    ll ans=-1;
    for(int i=0;i<=k;i++){
        int used=min(i+crit,n-1)-crit;
        int idx = lower_bound(vecb.begin(),vecb.end(),veca[min(i+crit,n-1)]+ta)-vecb.begin();
        idx=idx+(k-used);
        //cout<<crit<<" "<<i<<" "<<k<<" "<<used<<" "<<idx<<" "<<vecb[idx]<<endl;
        if(idx>=m){
            ans=-1;
            break;
        }
        if(vecb[idx]>=veca[min(i+crit,n-1)]+ta){
            ans=max(ans,vecb[idx]+tb);
        }
    }
    cout<<ans<<endl;
}
