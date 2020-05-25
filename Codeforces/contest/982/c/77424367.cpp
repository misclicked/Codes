#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> G[100005];
int l,r,ans;
int dfs(int n,int p){
    int nodes=0;
    for(auto it:G[n]){
        if(it!=p){
            if(dfs(it,n)%2==0)ans++;
            else nodes++;
        }
    }
    if(nodes%2)r++;
    else l++;
    return nodes+1;
}
int main(){
    int n;
    cin>>n;
    if(n&1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    l=r=ans=0;
    dfs(1,0);
    cout<<(ans?ans:0)<<endl;
}