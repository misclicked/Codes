#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXV = 1505000;
const ll INF = 1e9;
struct Edge{
	int v;
	ll f;
	ll re;
};
int n,s,t,level[MAXV];
vector<Edge> E[MAXV];
vector<Edge> Org[MAXV];
int now[MAXV];
#define SZ(x) ((int)(x).size())
void add_edge(int u, int v, ll f){
	E[u].push_back({v,f,SZ(E[v])});
	E[v].push_back({u,0,SZ(E[u])});
}
bool BFS(){
	for(int i=0;i<=n;i++)
		level[i]=-1;
	queue<int> que;
	que.push(s);level[s]=0;
	while(que.size()){
		int u=que.front(); que.pop();
		for(auto it:E[u]){
			if(it.f>0 && level[it.v]==-1){
				level[it.v]=level[u]+1;
				que.push(it.v);
			}
		}
	}
	return level[t]!=-1;
}
ll DFS(int u, ll nf){
	if(u==t)return nf;
	ll res=0;
	while(now[u]<SZ(E[u])){
		Edge &it = E[u][now[u]];
		if(it.f>0&&level[it.v]==level[u]+1){
			ll tf=DFS(it.v,min(nf,it.f));
			res+=tf;nf-=tf;it.f-=tf;
			E[it.v][it.re].f+=tf;
			if(nf==0)return res;
		}else now[u]++;
	}
	if(!res)level[u]=-1;
	return res;
}
ll flow(ll res=0){
	while(BFS()){
		ll tmp=0;
		memset(now,0,sizeof(now));
		while(tmp = DFS(s,INF)){
			res+=tmp;
		}
	}
	return res;
}
typedef pair<ll,ll> pii;
struct meal{
	ll s,t;
}chiefs[MAXV];
vector<ll> S;
set<ll> se;
int N;
int ANS;
bool ok(ll mid){
	int m=S.size();
	s=0,t=N+m+1;
	for(int i=0;i<=MAXV;i++)
		E[i].clear();
	for(int i=1;i<=N;i++){
		add_edge(s,i,mid);
	}
	n=t+1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<m-1;j++){
			if((chiefs[i].s<=S[j])&&(S[j+1]<=chiefs[i].t)){
				add_edge(i,N+j+1,INF);
			}
		}
	}
	for(int j=0;j<m-1;j++)add_edge(N+j+1,t,S[j+1]-S[j]);
	//cout<<mid*N<<endl;
	int hwhw=flow();
	//cout<<hwhw<<endl;
	if(hwhw==mid*N){
		ANS=mid*N;
		//cout<<ANS<<endl;
		return true;
	}
	return false;
}
int solve(){
	cin>>N;
	se.clear();
	S.clear();
	ll l=LLONG_MAX,r=-1,mid;
	for(int i=1;i<=N;i++){
		cin>>chiefs[i].s>>chiefs[i].t;
		se.insert(chiefs[i].t);
		se.insert(chiefs[i].s);
	}
	for(auto it:se){
		S.push_back(it);
	}
l=0;r=INT_MAX;
	while(l<=r){
		mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(!ok(mid)){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ANS<<endl;
	return 0;
}
int main(){
	return solve();
}