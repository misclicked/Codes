#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	//count complete tasks
	ll n,k,M;
	cin>>n>>k>>M;
	vector<ll> vec;
	for(ll i=0;i<k;i++){
		ll data;
		cin>>data;
		vec.push_back(data);
	}
	sort(vec.begin(),vec.end());
	ll ans=0;
	for(ll i=0;i<=n;i++){
		ll now=0;
		ll m=M;
		for(ll j=0;j<i;j++){
			for(ll r=0;r<k;r++){
				m-=vec[r];
				if(m<0)
					break;
				now++;
			}
			if(m<0)
				break;
			else{
				now++;
			}
		}
		//cout<<i<<" K "<<now<<endl;
		if(m<0){
			ans=max(now,ans);
			//cout<<i<<" "<<now<<endl;
			continue;
		}
		ll hehe=n-i;
		for(ll j=0;j<k;j++){
			for(ll r=0;r<hehe;r++){
				m-=vec[j];
				if(m<0){
					break;
				}
				now++;
			}
			if(m<0)
				break;
		}
		ans=max(ans,now);
		//cout<<i<<" "<<now<<endl;
	}
	cout<<ans<<endl;
}