#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int G[105];
int P[105];
pii ans[105];
vector<int> now;
bool vis[105];
int finda(int n){
	vis[n]=true;
	if(P[n]==0)return n;
	return finda(P[n]);
}
int findc(int n){
	vis[n]=true;
	if(G[n]==0)return n;
	return findc(G[n]);
}
int main(){
	memset(vis,0,sizeof(vis));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		G[a]=i;
		G[i]=b;
		P[i]=a;
		P[b]=i;
		ans[i]=pii(a,b);
	}
	finda(1);
	now.push_back(findc(1));
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			//cout<<i<<" "<<finda(i)<<" "<<findc(i)<<endl;
			now.push_back(finda(i));
			now.push_back(findc(i));
		}
	}
	/*for(int i=0;i<now.size();i++){
		cout<<now[i]<<" ";
	}
	cout<<endl;
	cout<<"ans: "<<endl;*/
	for(int i=0;i<now.size()-1;i+=2){
		ans[now[i]].second=now[i+1];
		ans[now[i+1]].first=now[i];
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}