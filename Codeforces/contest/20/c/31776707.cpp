#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> G[100005];
ll dis[100005];
int par[100005];
pll input[100005];
void print(int n){
	if(par[n]==n){
		cout<<n;
		return;
	} 
	print(par[n]);
	cout<<" "<<n;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)dis[i]=LLONG_MAX,par[i]=i;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back(pll(b,c));
		G[b].push_back(pll(a,c));
	}
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	pq.push(pll(0,1));
	dis[1]=0;
	while(!pq.empty()){
		int now=pq.top().second;;
		if(pq.top().first!=dis[now]){
			pq.pop();
			continue;
		}
		pq.pop();
		for(int i=0;i<G[now].size();i++){
			if(dis[now]+G[now][i].second<dis[G[now][i].first]){
				dis[G[now][i].first]=dis[now]+G[now][i].second;
				par[G[now][i].first]=now;
				pq.push(pll(dis[G[now][i].first],G[now][i].first));
			}
		}
	}
	if(dis[n]==LLONG_MAX){
		cout<<-1<<endl;
		return 0;
	}
	print(n);
}