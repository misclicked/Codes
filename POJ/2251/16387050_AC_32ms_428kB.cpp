#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<vector>
#include<set>
#include<sstream>
#include<map>
#include<stack>
#include<queue> 
using namespace std;
typedef long long ll;
struct Loc{
	int x,y,z;
	Loc(){};
	Loc(int _x,int _y,int _z):x(_x),y(_y),z(_z){};
};
char mape[35][35][35];
int dis[35][35][35];
int dir[6][3]={{1,0,0},{-1,0,0},
				{0,1,0},{0,0,1},{0,-1,0},{0,0,-1}};
int main(){
	int L,R,C;
	Loc st;
	queue<Loc> que;
	while(cin>>L>>R>>C&&(L||R||C)){
		for(int i=0;i<=L+1;i++)
			for(int j=0;j<=R+1;j++)
				for(int k=0;k<=C+1;k++)
					mape[i][j][k]='#';
		for(int i=1;i<=L;i++){
			for(int j=1;j<=R;j++){
				for(int k=1;k<=C;k++){
					cin>>mape[i][j][k];
					if(mape[i][j][k]=='S'){
						st.x=j;
						st.y=k;
						st.z=i;
					}
				}
			}
		}
		memset(dis,0,sizeof(dis));
		while(que.size())que.pop();
		que.push(st);
		int ans=0;
		while(que.size()){
			Loc now=que.front();
			que.pop();
			int D=dis[now.z][now.x][now.y];
			for(int i=0;i<6;i++){
				int Z=now.z+dir[i][0];
				int X=now.x+dir[i][1];
				int Y=now.y+dir[i][2];
				char C=mape[Z][X][Y];
				if(C=='E'){
					ans=D+1;
					break;
				}else if(C=='.'){
					mape[Z][X][Y]='#';
					dis[Z][X][Y]=D+1;
					que.push(Loc(X,Y,Z));
				}
			}
		}
		if(ans)
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else
			cout<<"Trapped!"<<endl;
	}
}
