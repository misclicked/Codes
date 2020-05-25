//
// Created by misclicked on 2019/5/14.
//

#pragma# GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n,m;
    cin>>n>>m;
    deque<ll> by,gl;
    by.resize(n);
    gl.resize(m);
    for(auto &it:by)cin>>it;
    for(auto &it:gl){
        cin>>it;
    }
    sort(by.begin(),by.end());
    sort(gl.begin(),gl.end());
    ll l=n-1;
    ll r=m-1;
    ll ans=0;
    ll now;
    while(l>=0){
        now=0;
        while(r>=0&&by[l]<=gl[r]){
            ans+=gl[r--];
            now++;
        }
        if((by[l]!=gl[r+1])&&now==m){
            ans-=gl[r+1];
            r++;
            now--;
        }else if(r>=0){
            now++;
            ans+=gl[r--];
        }
        if(by[l]>gl[0]){
            cout<<-1<<endl;
            return 0;
        }
        ans+=by[l]*(m-now);
        l--;
    }
    if(r==-1)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}
