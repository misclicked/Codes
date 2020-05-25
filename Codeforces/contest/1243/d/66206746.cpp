#include<bits/stdc++.h>
using namespace std;
unordered_set<int> graph[100005];
unordered_set<int> se;
void bfs(int u) {
	queue<int> q;
	q.push(u); 
	while(q.size()){
		u=q.front();
		q.pop(); 
		for(auto it=se.begin();it!=se.end();){
			int v=*it++;
			if(!graph[u].count(v))
				q.push(v),se.erase(v);
		}
	}
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
			bfs(i);
			cnt++;
		}
	}
	printf("%d\n",cnt-1);
} 