#include<bits/stdc++.h>
using namespace std;
unordered_set<long long int> graph;
unordered_set<int> se;
namespace IO{
	char ss[1<<17],*A=ss,*B=ss;
	inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
	template<class T>inline void sd(T&x){
		char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45){y=-1;}x=c-48;
		while(c=gc(),47<c&&c<58){x=x*10+c-48;}x*=y;
	}
}
using namespace IO;
unordered_set<int>::iterator bfs(int u) {
	queue<int> q;
	q.push(u);
	int v;
	while(q.size()){
		u=q.front();
		q.pop(); 
		for(unordered_set<int>::iterator it=se.begin();it!=se.end();){
			v=*it++;
			if(!graph.count(min(u,v)*1000000+max(u,v)))
				q.push(v),se.erase(v);
		}
	}
	return se.begin();
}
int main(){
	int n,m,a,b,cnt=0;
	sd(n),sd(m);
	for(int i=0;i<m;i++){
		sd(a),sd(b);
		graph.insert(min(a,b)*1000000+max(a,b));
	}
	for(int i=1;i<=n;i++)se.insert(i);
	unordered_set<int>::iterator now=se.begin();
	while((now=bfs(*now))!=se.end()){
		cnt++;
	}
	printf("%d\n",cnt);
} 