#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec[505];
ll w[505][505];
ll c[505][505];
ll mape[505];
ll sz[595];
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
	ll boii=0;ll total;
	for(ll i=0;i<n;i++){
		memset(mape,-1,sizeof(mape));
		ll now=0;
		if(vec[i].size()==0){
			w[i][0]=0;
			c[i][0]=0;
			sz[i]=1;
			continue;
		}
		total=vec[i].back()-vec[i].front()+1;
		boii+=total;
		for(ll j=0;j<vec[i].size();j++){
			ll cnt=j;
			for(ll k=vec[i].size()-1;k>=j;k--){
				if(cnt>K)break;
				mape[cnt]=max(mape[cnt],(total - (vec[i][k]-vec[i][j]+1)));
				cnt++;
			}
		}
		mape[vec[i].size()]=max(mape[vec[i].size()],total);
		int cnt=0;
		for(int j=0;j<=K;j++){
			if(mape[j]!=-1){
				c[i][cnt]=j;
				w[i][cnt++]=mape[j];
			}
		}
		sz[i]=cnt;
	}
	memset(f,0,sizeof(f));
	for(ll i=0;i<n;i++){
		for(ll v=K;v>=0;v--){
			for(ll j=0;j<sz[i];j++){
				if(v-c[i][j]>=0){
					f[v]=max(f[v],f[v-c[i][j]] + w[i][j]);
				}
			}
		}
	}
	cout<<boii-f[K]<<endl; 
}