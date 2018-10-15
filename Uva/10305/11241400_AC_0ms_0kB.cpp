#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int mape[105][105];
int deg[105],vis[105];
int anc;
bool flag=false,flagg=false;
int n,m;
vector<int> out;
int main() {
    while(cin>>n>>m&&n){
        memset(mape,0,sizeof(mape));
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            if(!mape[a][b])
                deg[a]++;
            mape[a][b]=1;
            mape[b][a]=-1;
        }
        out.clear();
        queue<int> que;
        for(int i=1;i<=n;i++){
            if(deg[i]==0&&!vis[i]){
                vis[i]=true;
                que.push(i);
            }
        }
        while(!que.empty()){
            int now = que.front();
            que.pop();
            out.push_back(now);
            for(int i=1;i<=n;i++){
                if(mape[now][i]==-1){
                    deg[i]--;
                    if(deg[i]<=0&&!vis[i])
                        que.push(i);
                }
            }
        }
        reverse(out.begin(),out.end());
        for(int i=0;i<out.size();i++){
            if(i)cout<<' ';
            cout<<out[i];
        }
        cout<<endl;
    }
}
