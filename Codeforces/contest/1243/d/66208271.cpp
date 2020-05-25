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
unordered_set<int>::iterator it;
int n,m,u,v,i,cnt=0;
unordered_set<int>::iterator now;
queue<int> q;
unordered_set<int>::iterator bfs() {
	q.push(*now);
	while(q.size()){
		u=q.front();
		q.pop(); 
		for(it=se.begin();it!=se.end();){
			v=*it++;
			if(!graph.count(u<v?v*1000000+u:u*1000000+v))
				q.push(v),se.erase(v);
		}
	}
	return se.begin();
}
int main(){
	sd(n),sd(m);
	for(i=0;i<m;i++){
		sd(u),sd(v);
		graph.insert(u<v?v*1000000+u:u*1000000+v);
	}
	for(i=1;i<=n;i++)se.insert(i);
	now=se.begin();
	while((now=bfs())!=se.end()){
		cnt++;
	}
	printf("%d\n",cnt);
} 