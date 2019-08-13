//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> table;

void build(int N){
    for(int i=2;i<=N;i++){
        bool ok=true;
        for(int j=2;j<i&&j<=ceil(sqrt(i));j++){
            if(i%j==0){
                ok=false;
                break;
            }
        }
        if(ok)table.push_back(i);
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
    int T;
    build(ceil(sqrt(1000000)));
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"No"<<endl;
            continue;
        }
        bool ok=true;
        for(int i=0;i<table.size()&&table[i]<=ceil(sqrt(n))&&table[i]<n;i++){
            if(n%table[i]==0){
                ok=false;
                break;
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
