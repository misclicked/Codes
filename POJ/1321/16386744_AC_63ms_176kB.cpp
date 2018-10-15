#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<vector>
#include<set>
#include<sstream>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> mape;
int col[10],row[10];
int n,m;
int ans;
void dfs(int i,int k){
	if(k==m){
		ans++;
		return;
	}
	for(;i<mape.size();i++){
		int x=mape[i].first;
		int y=mape[i].second;
		if(!col[x]&&!row[y]){
			col[x]=row[y]=true;
			dfs(i,k+1);
			col[x]=row[y]=false;
		}
	}
}
int main(){
	while(cin>>n>>m){
		if(n==-1&&m==-1)return 0;
		mape.clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char data;
				cin>>data;
				if(data=='#')
					mape.push_back(pii(i,j));
			}
		}
		ans=0;
		memset(col,0,sizeof(col));
		memset(row,0,sizeof(row));
		dfs(0,0);
		cout<<ans<<endl;
	}
}
