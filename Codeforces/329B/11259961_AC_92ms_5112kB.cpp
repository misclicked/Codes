#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char mape[1005][1005];
int dis[1005][1005];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m;
	cin>>n>>m;
	pii E,S;
	memset(mape,-1,sizeof(mape));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mape[i][j];
			dis[i][j]=INT_MAX;
			if(mape[i][j]=='E')
				E=pii(i,j);
			else if(mape[i][j]=='S')
				S=pii(i,j);
		}
	queue<pii> que;
	que.push(E);
	dis[E.first][E.second]=0;
	int ans=0;
	int Mdis=INT_MAX;
	while(!que.empty()){
		pii now=que.front();
		que.pop();
		int x=now.first,y=now.second;
		if(dis[x][y]>Mdis)
			break;
		if(isdigit(mape[x][y]))
			ans+=(mape[x][y]-'0');
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(isdigit(mape[nx][ny])&&dis[nx][ny]==INT_MAX){
				dis[nx][ny]=dis[x][y]+1;
				que.push(pii(nx,ny));
			}
			if(mape[nx][ny]=='S'&&dis[nx][ny]==INT_MAX){
				dis[nx][ny]=dis[x][y]+1;
				Mdis=dis[nx][ny];
				que.push(pii(nx,ny));
			}
		}
	}
	cout<<ans<<endl; 
}
