//
// Created by misclicked on 2019/5/14.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<ll,ll> dp;
const ll Inf = 1e15;
vector<int> money({1000,500,100,50,35,5,1});

ll calc(ll n){
    if(n<0)return Inf;
    if(dp.count(n))return dp[n];
    ll ans=Inf;
    for(int i=0;i<money.size();i++){
        ans=min(ans,calc(n-money[i])+1ll);
    }
    if(ans!=Inf)dp[n]=ans;
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    for(int i=0;i<money.size();i++)
        dp[money[i]]=1;
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        calc(n%1000ll);
        cout<<(dp[n%1000ll]+(n/1000ll))<<endl;
    }
}
