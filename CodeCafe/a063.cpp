//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> G[100005];
vector<int> GG[100005];
vector<int> E;

int deg[100005]={0};

bool vis[100005];

void dfs(int now,int color){
    vis[now]=true;
    E[now]=color;
    for(int i=0;i<GG[now].size();i++){
        if(!vis[GG[now][i]]){
            dfs(GG[now][i],color^1);
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
        deg[a]++;
        deg[b]++;
        E.push_back(0);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(deg[i]==2){
            vis[G[i][0].second]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++){
            for(int k=0;k<G[i].size();k++){
                GG[G[i][j].second].push_back(G[i][k].second);
            }
        }
    }
    for(int i=0;i<m;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<E.size();i++){
        cout<<E[i];
    }
    cout<<endl;
}
