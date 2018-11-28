#include<iostream>	//cin,cout
#include<cstring>	//memset(arr,0,sizeof(arr))
#include<algorithm>	//max(a,b)
using namespace std;
int mape[105][105];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int i,int j){
	int now=1;
	mape[i][j]=0;					//fill currnet spot with 0 witch means "no water"
	for(int k=0;k<4;k++){			//iterate nearby 4 blocks
		int ni=i+dir[k][0];
		int nj=j+dir[k][1];
		if(mape[ni][nj])			//if there's water nearby, do dfs recursivly
			now+=dfs(ni,nj);		
	}
	return now;
}
int main(){
	memset(mape,0,sizeof(mape));	//fill mape[105][105] with 0 
	int n,m,k;
	cin>>n>>m>>k;					//input
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		mape[a][b]=1;				//if (i,j) have water mape[i][j]=1
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mape[i][j]){			//if (i,j) have water, use dfs to find lake size connected with (i,j)
				ans=max(ans,dfs(i,j));
			}
		}
	}
	cout<<ans<<endl;
}
