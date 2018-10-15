#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int G[205];
int vis[205];
ll dis[205];
ll ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>G[i];
	}
	ans=1;
	ll Max=-1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		int now=i;
		memset(vis,0,sizeof(vis));
		while(!vis[now]){
			dis[now]=cnt++,vis[now]=true,now=G[now];
		}
		Max=max(Max,dis[now]);
		ans=ans/__gcd(ans,cnt-dis[now])*(cnt-dis[now]);
	}
	cout<<max(ans,(((Max-1)/ans+1)*ans))<<endl;
}
