//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> G[10005];
ll dis[10005];
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
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    int A,B;
    cin>>A>>B;
    for(int i=0;i<n;i++)
        dis[i]=1ll<<60;
    dis[A]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,A});
    while(pq.size()){
        pii now=pq.top();
        pq.pop();
        for(int i=0;i<G[now.second].size();i++){
            if(dis[now.second]+G[now.second][i].second<dis[G[now.second][i].first]){
                dis[G[now.second][i].first]=dis[now.second]+G[now.second][i].second;
                pq.push({dis[G[now.second][i].first],G[now.second][i].first});
            }
        }
    }
    cout<<dis[B]<<endl;
}
