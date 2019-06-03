//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int out[300005];
vector<int> vec[300005];
int vis[300005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    memset(out,0,sizeof(out));
    memset(vis,0,sizeof(vis));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vec[b].push_back(a);
        out[a]++;
    }
    queue<int> que;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(out[i]==0)que.push(i);
    }
    while(que.size()){
        int now=que.front();
        que.pop();
        vis[now]=true;
        ans.push_back(now);
        for(auto it:vec[now]){
            out[it]--;
            if(out[it]==0)
                que.push(it);
        }
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()){
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        for(int i=1;i<=n;i++){
            if(!vis[i])
                cout<<" "<<i;
        }
        cout<<endl;
    }else{
        cout<<1;
        for(int i=2;i<=n;i++){
            cout<<" "<<i;
        }
        cout<<endl;
    }

}
