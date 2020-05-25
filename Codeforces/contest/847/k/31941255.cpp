#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long int ll;
ll n,a,b,k,f;
string u,v;
map<string, map<string, ll> > mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>a>>b>>k>>f;
	string last="";
	for(int i=0;i<n;i++){
		cin>>u>>v;
		if(u==last){
			last=v;
			if(u>v)swap(u,v);
			mp[u][v]+=b;
		}
		else{
			last=v;
			if(u>v)swap(u,v);
			mp[u][v]+=a;
		}
	}
	vector<ll> cst;
	ll ans=0;
	for(auto it:mp){
		//cout<<it.first<<":";
		for(auto it2:it.second){
			//cout<<it2.first<<" ";
			cst.push_back(it2.second);
			ans+=it2.second;
		}
		//cout<<endl;
	}
	sort(cst.begin(),cst.end());
	/*for(auto it:cst)cout<<it<<" ";
	cout<<endl;*/
	for(int i=cst.size()-1;k>0&&i>=0;i--){
		if(f<cst[i]){
			//cout<<"rep "<<cst[i]<<" to "<<f<<endl;
			k--;
			ans-=cst[i];
			ans+=f;
		}
	}
	cout<<ans<<endl;
}
