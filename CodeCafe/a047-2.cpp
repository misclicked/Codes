//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> G[300005];
pii ETT[22][600010];
int tab[300005];
int N,Q,cnt,dep,par;

void DFS(int now){
    int tmp=par;
    tab[now]=min(tab[now],cnt);
    ETT[0][cnt].first=dep;
    ETT[0][cnt++].second=now;
    for(int i=0;i<G[now].size();i++){
        if(G[now][i]!=par){
            dep++;
            par=now;
            DFS(G[now][i]);
            par=tmp;
            dep--;
            ETT[0][cnt].first=dep;
            ETT[0][cnt++].second=now;
        }
    }
}

int k,ret;
inline int RMQ(int a,int b){
    k=__lg(b-a+1);
    if(ETT[k][a].first<ETT[k][b-(1<<k)+1].first){
        ret=ETT[k][a].second;
    }else{
        ret=ETT[k][b-(1<<k)+1].second;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int a,b;
    scanf("%d %d",&N,&Q);
    for(int i=0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    memset(tab,1,sizeof(tab));
    cnt=0;
    dep=1,par=-1;
    DFS(0);
    for(int j=1;(1<<j)<=cnt;j++){
        for(int i=0;(i+(1<<j))<=cnt;i++)
            if(ETT[j-1][i].first>ETT[j-1][i+(1<<(j-1))].first)
                ETT[j][i]=ETT[j-1][i+(1<<(j-1))];
            else
                ETT[j][i]=ETT[j-1][i];
    }
    while(Q--){
        scanf("%d %d",&a,&b);
        a--;b--;
        if(tab[a]>tab[b])swap(a,b);
        int an=RMQ(tab[a],tab[b]);
        if(an==a){
            cout<<a+1<<" is an ancestor of "<<b+1<<endl;
        }else if(an==b){
            cout<<b+1<<" is an ancestor of "<<a+1<<endl;
        }else{
            cout<<"Nothing"<<endl;
        }
    }
}
