#include <bits/stdc++.h>
using namespace std;
string ans="";
int n;
vector<int> vec;
int dp[100005][2]={0};
char ansNow;
bool dfs(int now,int turn){
    if(dp[now][turn])return dp[now][turn];
    if(turn){
        //Alice
        bool can=false;
        for(int i=now+vec[now];i<n;i+=vec[now]){
            if(vec[i]>vec[now])
                can=can||dfs(i,turn^1);
        }
        for(int i=now-vec[now];i>=0;i-=vec[now]){
            if(vec[i]>vec[now])
                can=can||dfs(i,turn^1);
        }
        return dp[now][turn]=can;
    }else{
        //Bob
        bool can=true;
        for(int i=now+vec[now];i<n;i+=vec[now]){
            if(vec[i]>vec[now])
                can=can&&dfs(i,turn^1);
        }
        for(int i=now-vec[now];i>=0;i-=vec[now]){
            if(vec[i]>vec[now])
                can=can&&dfs(i,turn^1);
        }
        return dp[now][turn]=can;
    }
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        vec.emplace_back(d);
    }
    for(int i=0;i<n;i++){
        cout<<(dfs(i,1)?'A':'B');
    }
}
