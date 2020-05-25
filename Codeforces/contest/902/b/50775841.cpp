#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> vec[10005];
int col[10005]={0};
int ans;
void dfs(int now, int color, int parent){
	for(int i=0;i<vec[now].size();i++){
		int v = vec[now][i];
		if(v==parent)continue;
		if(color!=col[v])ans++;
		dfs(v,col[v],now);
	}
}
int main(){
	int n;
	cin>>n;
	for(int u=2;u<=n;u++){
		int v;
		cin>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}
	ans=1;
	dfs(1,col[1],0);
	cout<<ans<<endl;
}
