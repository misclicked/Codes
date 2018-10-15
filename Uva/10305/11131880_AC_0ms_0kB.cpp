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
        /*for(int i=1;i<=n;i++){
            cout<<"deg "<<i<<" "<<deg[i]<<endl;
        }*/
        out.clear();
        int now=0;
        while(out.size()!=n){
            for(int i=1;i<=n;i++){
                if(deg[i]==0&&!vis[i]){
                    //cout<<i<<endl;
                    vis[i]=true;
                    out.push_back(i);
                    /*for(int j=1;j<=n;j++){
                        if(mape[i][j]==-1){
                            deg[j]--;
                            //cout<<j<<" "<<deg[j]<<endl;
                        }
                    }*/
                    //system("pause");
                }
            }
            for(;now<out.size();now++){
                for(int i=1;i<=n;i++){
                    if(mape[out[now]][i]==-1){
                        deg[i]--;
                    }
                }
            }
        }
        reverse(out.begin(),out.end());
        for(int i=0;i<out.size();i++){
            if(i)cout<<' ';
            cout<<out[i];
        }
        cout<<endl;
        for(int i=0;i<out.size()-1;i++){
            for(int j=i;j<out.size();j++){
                if(mape[out[i]][out[j]]==-1)
                    cout<<out[i]<<" "<<out[j]<<" bug"<<endl;
            }
        }
    }
}
