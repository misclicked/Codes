#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
int table[1111111];
int poi[1111111];
int parent(int a){
	if(table[a]==a)
		return a;
	return table[a]=parent(table[a]);
}
void uni(int a,int b){
	table[parent(b)]=parent(a);
}
int main(){
	int t;
	int a,b;
	cin>>t;
	while(t--){
		memset(poi,0,sizeof(poi));
		memset(table,0,sizeof(table));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			table[i]=i;
		while(m--){
			cin>>a>>b;
			uni(a,b);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			poi[parent(i)]++;
			ans=max(poi[parent(i)],ans);
		}
		cout<<ans<<endl;
	}
}