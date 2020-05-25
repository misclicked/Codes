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
unordered_set<int>::iterator it,now;
int n,m,u,v,i,cnt=0,ft=0,rr=0;
int q[100005];
void bfs() {
	q[rr++]=*now;
	se.erase(*now);
	while(rr-ft){
		u=q[ft++];
		for(it=se.begin();it!=se.end();){
			v=*it++;
			if(!graph.count(u<v?v*1000000+u:u*1000000+v)){
				q[rr++]=v,se.erase(v);
			}
		}
	}
	now=se.begin();
}
int main(){
	sd(n),sd(m);
	for(i=0;i<m;i++){
		sd(u),sd(v);
		graph.insert(u<v?v*1000000+u:u*1000000+v);
	}
	for(i=1;i<=n;i++)se.insert(i);
	now=se.begin();
	while(now!=se.end()){
		bfs();
		cnt++;
	}
	printf("%d\n",cnt-1);
} 