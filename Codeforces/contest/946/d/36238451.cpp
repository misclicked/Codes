#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec[505];
vector<ll> w[505];
vector<ll> c[505];
ll mape[505];
typedef pair<ll,ll> pii;
ll f[505];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll n,m,K;
	cin>>n>>m>>K;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='1') 
				vec[i].push_back(j);
		}
	}
	ll boii=0;
	for(ll i=0;i<n;i++){
		memset(mape,-1,sizeof(mape));
		ll now=0;
		if(vec[i].size()==0){
			w[i].push_back(0);
			c[i].push_back(0);
			continue;
		}
		ll total=vec[i].back()-vec[i].front()+1;
		boii+=total;
		for(ll j=0;j<vec[i].size();j++){
			ll cnt=j;
			bool ready=false;
			for(ll k=vec[i].size()-1;k>=j;k--){
				if(cnt>K)continue;
				mape[cnt]=max(mape[cnt],(total - (vec[i][k]-vec[i][j]+1)));
				cnt++;
			}
		}
		mape[vec[i].size()]=max(mape[vec[i].size()],total);
		for(int j=0;j<=K;j++){
			if(mape[j]!=-1){
				c[i].push_back(j);
				w[i].push_back(mape[j]);
			}
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<w[i].size();j++){
			cout<<i<<" "<<w[i][j]<<" "<<c[i][j]<<endl;
		}
	}*/
	memset(f,0,sizeof(f));
	for(ll i=0;i<n;i++){
		for(ll v=K;v>=0;v--){
			for(ll j=0;j<w[i].size();j++){
				if(v-c[i][j]>=0){
					f[v]=max(f[v],f[v-c[i][j]] + w[i][j]);
				}
			}
		}
	}
	cout<<boii-f[K]<<endl; 
}