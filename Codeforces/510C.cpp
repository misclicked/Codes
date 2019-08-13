//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<string> input;
int mape[30][30];
int deg[30],vis[30];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    memset(mape,0,sizeof(mape));
    memset(deg,0,sizeof(deg));
    memset(vis,0,sizeof(vis));
    int n;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        input.push_back(str);
    }
    for(int i=0;i<n-1;i++){
        int diff=0;
        bool flag=false;
        while(input[i][diff]==input[i+1][diff]){
            diff++;
            if(diff>=input[i].size()||diff>=input[i+1].size()){
                flag=true;
                break;
            }
        }
        if(flag){
            if(input[i].size()>input[i+1].size()){
                cout<<"Impossible"<<endl;
            }else{
                continue;
            }
        }
        int a=input[i][diff]-'a';
        int b=input[i+1][diff]-'a';
        if(!mape[a][b]){
            deg[a]++;
        }
        mape[a][b]=1;
        mape[b][a]=-1;
    }
    queue<int> que;
    for(int i=0;i<26;i++){
        if(deg[i]==0){
            vis[i]=true;
            que.push(i);
        }
    }
    vector<int> ans;
    while(!que.empty()){
        int now=que.front();
        que.pop();
        ans.push_back(now);
        for(int i=0;i<26;i++) {
            if(mape[now][i]==-1){
                deg[i]--;
                if(deg[i]<=0&&!vis[i]){
                    vis[i]=true;
                    que.push(i);
                }
            }
        }
    }
    if(ans.size()!=26){
        cout<<"Impossible"<<endl;
        return 0;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<(char)(ans[i]+'a');
    cout<<endl;
}
