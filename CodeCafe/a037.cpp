//
// Created by misclicked on 2019/5/14.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int np[300005];
int nxt[300005];
vector<int> primes;

void build(){
    np[0]=true;
    np[1]=true;
    for(int i=2;i<300000;i++){
        if(!np[i])
            primes.push_back(i);
        for(int j=0;primes[j]*i<300000;j++){
            np[primes[j]*i]=true;
            if(i%primes[j]==0)
                break;
        }
    }
}

vector<int> ans;
set<int> se;
int n;

void dfs(int idx){
    if(idx==n){
        cout<<ans[0];
        for(int i=1;i<n;i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
        exit(0);
    }
    for(int i=1;i<=n;i++){
        if(nxt[i]&&!np[ans[idx-1]+i]){
            ans.push_back(i);
            nxt[i]=0;
            dfs(idx+1);
            nxt[i]=1;
            ans.pop_back();
        }
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
    build();
    cin>>n;
    for(int i=1;i<=n;i++){
        nxt[i]=1;
    }
    for(int i=1;i<=n;i++){
        ans.push_back(i);
        dfs(1);
        ans.pop_back();
    }
}
