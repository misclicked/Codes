#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll input[222222];
int main(){
    memset(input,0,sizeof(input));
    ll n;
    cin>>n;
    ll data;
    ll MIN=INT_MAX;
    ll last;
    for(ll i=0;i<n;i++){
        cin>>input[i];
        if(input[i]<MIN)
            MIN=input[i];      
    }
    ll cnt=0;
    bool flag=false;
    vector<ll> sol;
    for(ll i=0;i<n;i++){
        if(input[i]==MIN)
            sol.push_back(i);
    }
    sol.push_back(n+sol[0]);
    for(ll i=0;i<sol.size()-1;i++){
        cnt=max(sol[i+1]-sol[i],cnt);
    }
    cout<<MIN*n+cnt-1<<endl;
}