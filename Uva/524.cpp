//
// Created by misclicked on 2019/5/15.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int np[300005];
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
    if(idx==n&&!np[ans[0]+ans.back()]){
        cout<<ans[0];
        for(int i=1;i<n;i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
        return;
    }
    vector<int> tmp;
    for(auto it:se)tmp.push_back(it);
    for(auto it:tmp){
        if(!np[ans[idx-1]+it]){
            ans.push_back(it);
            se.erase(it);
            dfs(idx+1);
            se.insert(it);
            ans.pop_back();
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T=1;
    build();
    while(cin>>n){
        if(T!=1)cout<<endl;
        cout<<"Case "<<T++<<":"<<endl;
        ans.clear();
        se.clear();
        for(int i=2;i<=n;i++)
            se.insert(i);
        ans.push_back(1);
        dfs(1);
    }
}
