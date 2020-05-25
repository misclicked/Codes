#include<bits/stdc++.h>
using namespace std;
unordered_set<int> graph[100005];
unordered_set<int> se;
void dfs(int u){
	vector<int> era;
	for(int v:se)
		if(!graph[u].count(v))
			era.push_back(v);
	for(int v:era)
		se.erase(v); 
	for(int v:era)
		dfs(v);
}
int main(){
	int n,m,a,b,cnt=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	for(int i=1;i<=n;i++)se.insert(i);
	for(int i=1;i<=n;i++){
		if(se.count(i)){
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n",cnt-1);
} 