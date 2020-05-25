#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
unordered_set<ll> graph[100005];
unordered_set<ll> se;
void dfs(int u){
	vector<ll> era;
	era.clear();
	for(ll v:se)
		if(!graph[u].count(v))
			era.push_back(v);
	for(ll v:era)
		se.erase(v); 
	for(ll v:era)
		dfs(v);
}
int main(){
	ll n,m;
	cin>>n>>m;
	ll a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	for(int i=1;i<=n;i++)se.insert(i);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(se.count(i)){
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt-1<<endl;
} 