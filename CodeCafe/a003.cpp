//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<ll,int> um;
set<int> se;
vector<int> vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n,m,data,sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>data;
        vec.push_back(data);
        sum+=data;
    }
    ll ans=0;
    ll now,sz,tmp;
    while(m){
        now=0;
        sz=0;
        tmp=m;
        for(int i=0;i<n;i++){
            if(tmp>=vec[i]){
                tmp-=vec[i];
                now+=vec[i];
                sz++;
            }
        }
        if(now==0)break;
        ans+=sz*(m/now);
        m%=now;
    }
    cout<<ans<<endl;

}
