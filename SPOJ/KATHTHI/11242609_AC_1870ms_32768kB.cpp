#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<int,pii> pipii;
char mape[1005][1005];
ll dis[1005][1005];
ll dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int main(){
	//freopen("KATHTHIin.txt","r",stdin);
	ll t,r,c;
	scanf("%lld",&t);
	deque<pii> dq;
	while(t--){
		scanf("%lld %lld",&r,&c);
		getchar();
		memset(dis,0,sizeof(dis));
		for(ll i=1;i<=r;i++){
			fgets(mape[i]+1,10000,stdin);
		}
		//if(t!=97)continue;
		while(!dq.empty())dq.pop_front();
		dq.push_back(pii(1,1));
		dis[1][1]=1;
		while(!dq.empty()){
			pii now=dq.front();
			dq.pop_front();
			ll x=now.first;
			ll y=now.second;
			for(int i=0;i<4;i++){
				ll nx=x+dir[i][0];
				ll ny=y+dir[i][1];
				ll nn=(mape[nx][ny]==mape[x][y])?0:1;
				if(nx<1||ny<1||nx>r||ny>c)continue;
				if(isalpha(mape[nx][ny])&&(dis[x][y]+nn<dis[nx][ny]||!dis[nx][ny])){
					dis[nx][ny]=dis[x][y]+nn;
					if(nn)
						dq.push_back(pii(nx,ny));
					else
						dq.push_front(pii(nx,ny));
				}
			}
		}
		/*for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cout<<dis[i][j]<<" ";
			}
			cout<<endl;
		}*/
		printf("%lld\n",dis[r][c]-1);
	}
}
