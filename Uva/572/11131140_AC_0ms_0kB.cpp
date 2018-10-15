#include <bits/stdc++.h>

using namespace std;

char mape[105][105];
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
int cnt=0;
void DFS(int x,int y){
    mape[x][y]='*';
    for(int i=0;i<8;i++){
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(mape[nx][ny]=='@')
            DFS(nx,ny);
    }
}
int main() {
    int n,m;
    while(cin>>n>>m&&n&&m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mape[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mape[i][j]=='@'){
                    ans++;
                    DFS(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
}