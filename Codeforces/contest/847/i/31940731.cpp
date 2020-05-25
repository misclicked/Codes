#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long int ll;
ll n,m,q,p;
char mp[256][256];
ll v[256][256];
bool vis[256][256];
int main(){
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m>>q>>p;
	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)mp[i][j]='*';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	int dx[]={0,0,-1,1};
	int dy[]={1,-1,0,0};
	struct nd{
		int x,y;
		ll l;
	};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mp[i][j]>='A'&&mp[i][j]<='Z'){
				queue<nd>qs;
				qs.push({i,j,q*(mp[i][j]-'A'+1)});
				//cout<<i<<" "<<j<<endl;
				//cout<<mp[i][j]<<":"<<q*(mp[i][j]-'A'+1)<<endl;
				memset(vis,0,sizeof(vis));
				vis[i][j]=true;
				while(!qs.empty()){
					nd s=qs.front();
					qs.pop();
					v[s.x][s.y]+=s.l;
					if(s.l>1){
						for(int k=0;k<4;k++){
							int xx=s.x+dx[k];
							int yy=s.y+dy[k];
							if(mp[xx][yy]!='*'&&!vis[xx][yy])vis[xx][yy]=true,qs.push({xx,yy,s.l/2});
						}
					}
				}
			}
		}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<setw(5)<<v[i][j]<<" ";
			if(v[i][j]>p)ans++;
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
}
