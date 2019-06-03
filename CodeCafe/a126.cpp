//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll n,m;
vector<ll> vec;
vector<ll> ans;
bool mape[10000005];
ll tot;
void dfs(ll now){
    if(tot==m){
        if(now!=n)return;
        cout<<"true\n"<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
        exit(0);
    }
    if(now>=n)return;
    for(ll i=1;(tot+i*vec[now])<=m;i++){
        ans.push_back(i);
        tot+=i*vec[now];
        //cout<<tot<<" "<<i<<" "<<now<<" "<<vec[now]<<endl;
        if(!mape[tot*(now+1)]){
            mape[tot*(now+1)]=true;
            dfs(now+1);
        }
        tot-=i*vec[now];
        ans.pop_back();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin>>n>>m;
    vec.resize(n);
    for(auto &it:vec){
        cin>>it;
    }
    memset(mape,0,sizeof(mape));
    dfs(0);
    cout<<"false"<<endl;
}
