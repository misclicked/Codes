#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> vec[100005];
set<ll> se;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		vec[a].push_back(b);
	}
	for(int i=1;i<=m;i++){
		if(vec[i].empty())continue;
		se.insert(i);
		sort(vec[i].begin(),vec[i].end(),greater<int>());
		for(int j=1;j<vec[i].size();j++){
			vec[i][j]+=vec[i][j-1];
		}
	}
	ll ans,now;
	ans=0;
	vector<ll> rmv;
	for(int i=1;se.size();i++){
		now=0;
		rmv.clear();
		for(auto it:se){
			if(vec[it].size()<i){
				rmv.push_back(it);
				continue;
			}
			else if(vec[it][i-1]>0) now+=vec[it][i-1];
		}
		ans=max(now,ans);
		for(auto it:rmv){
			se.erase(it);
		}
	}
	cout<<ans<<endl;
}
