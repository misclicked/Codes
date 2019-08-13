//
// Created by misclicked on 2019/4/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int col[5005];
int row[5005];
vector<pii> TL,LR;
vector<pii> ans;
int n;
bool ok=false;
void dfs(int now){
    if(ok)return;
    if(now==n){
        for(int i=0;i<n;i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        ok=true;
        return;
    }
    for(int i=TL[now].first;i<=LR[now].first;i++){
        for(int j=TL[now].second;j<=LR[now].second;j++){
            if(!row[i]&&!col[j]){
                int test=rand();
                //cout<<now<<" "<<i<<" "<<j<<" IN"<<test<<endl;
                row[i]=1;
                col[j]=1;
                ans.push_back({i,j});
                dfs(now+1);
                row[i]=0;
                col[j]=0;
                ans.pop_back();
                //cout<<now<<" "<<i<<" "<<j<<" OUT"<<test<<endl;
            }
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    while(cin>>n&&n){
        int lx,ly,rx,ry;
        for(int i=0;i<n;i++) {
            cin >> lx >> ly >> rx >> ry;
            TL.push_back({lx, ly});
            LR.push_back({rx, ry});
        }
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        ans.clear();
        ok=false;
        dfs(0);
        if(!ok)
            cout<<"IMPOSSIBLE"<<endl;
    }
}