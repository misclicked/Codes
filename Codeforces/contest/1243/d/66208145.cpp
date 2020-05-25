#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef cc_hash_table<ll, ll, hash<ll>> ht;
ht graph;
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
	se.erase(u);
	while(q.size()){
		u=q.front();
		q.pop(); 
		for(it=se.begin();it!=se.end();){
			v=*it++;
			if(!graph[min(u,v)*1000000+max(u,v)]){
				q.push(v),se.erase(v);
			}
		}
	}
	return se.begin();
}
int main(){
	sd(n),sd(m);
	for(i=0;i<m;i++){
		sd(a),sd(b);
		graph[min(a,b)*1000000+max(a,b)]=1;
	}
	for(i=1;i<=n;i++)se.insert(i);
	unordered_set<int>::iterator now=se.begin();
	while((now=bfs(*now))!=se.end()){
		cnt++;
	}
	printf("%d\n",cnt);
} 