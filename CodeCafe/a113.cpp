//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> G[1000006];

void DFS(int now){
    if(G[now].size()!=2&&G[now].size()!=0){
        cout<<"No"<<endl;
        exit(0);
    }
    for(int i=0;i<G[now].size();i++){
        DFS(G[now][i]);
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        G[a].push_back(i+1);
    }
    DFS(1);
    cout<<"Yes"<<endl;
}
