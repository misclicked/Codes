#include<bits/stdc++.h>
using namespace std;
unordered_set<int> graph;
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
unordered_set<int>::iterator it;
int n,m,a,b,v,i,cnt=0;
queue<int> q;
unordered_set<int>::iterator bfs(int u) {
	q.push(u);
	while(q.size()){
		u=q.front();
		q.pop(); 
		for(it=se.begin();it!=se.end();){
			v=*it++;
			if(!graph.count(min(u,v)*100000+max(u,v)))
				q.push(v),se.erase(v);
		}
	}
	return se.begin();
}
int main(){
	sd(n),sd(m);
	for(i=0;i<m;i++){
		sd(a),sd(b);
		graph.insert(min(a,b)*100000+max(a,b));
	}
	for(i=1;i<=n;i++)se.insert(i);
	unordered_set<int>::iterator now=se.begin();
	while((now=bfs(*now))!=se.end()){
		cnt++;
	}
	printf("%d\n",cnt);
} 