#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int mape[30][30];
int deg[30],vis[30];
int anc;
bool flag=false,flagg=false;
int n,m;
vector<int> out;
vector<string> input;
int main() {
    cin>>n;
    memset(mape,0,sizeof(mape));
    memset(deg,0,sizeof(deg));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        string data;
        cin>>data;
        input.push_back(data);
    }
    for(int i=0;i<input.size()-1;i++){
        for(int j=i+1;j<input.size();j++){
            int diff=0;
            while(input[i][diff]==input[j][diff]){
                diff++;
                if(diff>=input[i].size()||diff>=input[j].size())
                    break;
            }
            if(diff>=input[i].size()||diff>=input[j].size()){
                if(input[j].size()<input[i].size()){
                    cout<<"Impossible"<<endl;
                    return 0;
                }else
                    continue;
            }
            int a=input[i][diff]-'a';
            int b=input[j][diff]-'a';
            if(!mape[a][b]){
                deg[a]++;
            }
            mape[a][b]=1;
            mape[b][a]=-1;
        }
    }
    out.clear();
    queue<int> que;
    for(int i=0;i<26;i++){
        if(deg[i]==0&&!vis[i]){
            vis[i]=true;
            que.push(i);
        }
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        out.push_back(now);
        for(int i=0;i<26;i++){
            if(mape[now][i]==-1){
                deg[i]--;
                if(deg[i]<=0&&!vis[i])
                    que.push(i);
            }
        }
    }
    if(out.size()!=26){
        cout<<"Impossible"<<endl;
        return 0;
    }
    reverse(out.begin(),out.end());
    for(int i=0;i<out.size();i++){
        cout<<(char)(out[i]+'a');
    }
    cout<<endl;
}
