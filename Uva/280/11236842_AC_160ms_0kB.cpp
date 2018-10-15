#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > vec(105);
bool vis[105];
int cnt=0;
void DFS(int n){
    for(int i=0;i<vec[n].size();i++){
        if(!vis[vec[n][i]]){
            cnt++;
            vis[vec[n][i]]=true;
            DFS(vec[n][i]);
        }
    }
}
int main() {
    int n;
    while(cin>>n,n){
        for(int i=1;i<=n;i++)vec[i].clear();
        int st,ed;
        while(cin>>st,st){
            while(cin>>ed,ed){
                vec[st].push_back(ed);
            }
        }
        int m,res;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>res;
            memset(vis,0,sizeof(vis));
            cnt=0;
            DFS(res);
            cout<<n-cnt;
            for(int i=1;i<=n;i++)
                if(!vis[i]) cout<<' '<<i;
            cout<<endl;
        }
    }
}