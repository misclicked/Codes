#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> vec;
ll t,n,p,k,data,ans;
ll dp[200005];
ll check(ll m){
	int price=0;
	for(int i=0;i<(m/k);i++){
		price+=vec[m-1-(k)*i];
	}
	price+=dp[m%k];
	return price<=p;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie(); 
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		dp[0]=0;
		vec.clear();
		for(ll i=0;i<n;i++){
			cin>>data;
			vec.push_back(data);		
		}
		sort(vec.begin(),vec.end());
		for(ll i=0;i<n;i++){
			dp[i+1]=dp[i]+vec[i];
		}
		ll l=0,r=n,mid;
		ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
}