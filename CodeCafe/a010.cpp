//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define MOD 998224350ll

vector<int> table[1010];
int calc[1010];

void build(){
    for(int i=0;i<1005;i++){
        int org,now;
        org=now=i;
        for(int j=2;j<=now;j++){
            while(now%j==0){
                now/=j;
                table[org].push_back(j);
            }
        }
    }
}

ll C(int n,int r){
    ll ret=1;
    memset(calc,0,sizeof(calc));
    for(ll i=r+1;i<=n;i++){
        for(int j=0;j<table[i].size();j++){
            calc[table[i][j]]++;
        }
    }
    for(ll i=1;i<=(n-r);i++){
        for(int j=0;j<table[i].size();j++){
            calc[table[i][j]]--;
        }
    }
    for(ll i=0;i<1005;i++){
        for(ll j=0;j<calc[i];j++){
            ret=(ret*i)%MOD;
        }
    }
    return ret%MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    build();
    int N,r,n;
    cin>>N;
    while(N--){
        cin>>n>>r;
        cout<<C(n,r)<<endl;
    }
}
