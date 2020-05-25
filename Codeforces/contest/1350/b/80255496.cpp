#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
ll table[100005];
int main() {
	int t;
	cin>>t;
	map<int,vector<int> > mp;
	vector<pii> update;
	while(t--){
		ll n,ans;
		cin>>n;
		mp.clear();
		for(int i=1;i<=n;i++){
			ll d;
			cin>>d;
			table[i]=0;
			mp[d].push_back(i); 
		}
		ans=0;
		for(auto it:mp){
			auto vec=it.second;
			update.clear();
			for(auto ee:vec){
				ll tmp=0;
				for(int i=1;i*i<=ee;i++){
					if(ee%i==0){
						tmp=max(tmp,table[i]+1);
						tmp=max(tmp,table[ee/i]+1);
					}
				}
				update.push_back({ee,tmp}); 
				ans=max(tmp,ans);
				//cout<<it<<" "<<tmp<<endl;
			}
			for(auto it:update){
				table[it.first]=it.second;
			};
		}
		cout<<ans<<endl;
	}
}
