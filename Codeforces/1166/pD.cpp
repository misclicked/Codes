//
// Created by misclicked on 2019/5/26.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> vec;
ll a,b,m;
vector<ll> vans;
bool ok=false;
ll sz=0;
ll bound=0;
ll total=0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b>>m;
        sz=floorl(log2l(b/((a+1)*1.0)));
        bound = b-powl(2,sz)*(a+1);
        sz+=2;
        if(a==b){
            cout<<1<<" "<<a<<endl;
            continue;
        }
        vans.clear();
        vans.push_back(a);
        ll tt=a;
        ll now=0;
        for(int i=1;i<sz-1;i++){
            ll base = powl(2,sz-i-2);
            now = min(m-1,bound/base);
            vans.push_back(tt+now+1);
            tt+=tt+now+1;
            bound-=base*(now);
        }
        if(bound<m){
            if(vans.back()!=b)
                vans.push_back(b);
            cout<<vans.size();
            for(auto it:vans){
                cout<<" "<<it;
            }
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
