//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> G[300005];
int an[30][300005];
int dep[300005];
int N,Q;

void DFS(int now,int par){
    for(int i=0;i<G[now].size();i++){
        if(G[now][i]!=par){
            dep[G[now][i]]=dep[now]+1;
            an[0][G[now][i]]=now;
            DFS(G[now][i],now);
        }
    }
}

void build(){
    for(int i=0;i<log2(N);i++){
        for(int j=1;j<=N;j++){
            if(an[i][j]==1||an[i][an[i][j]]==1){
                an[i+1][j]=1;
            }else{
                an[i+1][j]=an[i][an[i][j]];
            }
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
    cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dep[1]=0;
    DFS(1,0);
    build();
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(dep[a]>=dep[b])swap(a,b);
        int A=a,B=b;
        int diff=dep[b]-dep[a];
        for(int i=log2(N);i>=0;i--){
            if(diff&(1<<i)){
                b=an[i][b];
            }
        }
        if(a==b){
            cout<<A<<" is an ancestor of "<<B<<endl;
        }else{
            cout<<"Nothing"<<endl;
        }
    }
}
