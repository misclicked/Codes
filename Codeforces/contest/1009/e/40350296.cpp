#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 998244353
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll n;
	vector<ll> vec;
	cin>>n;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		vec.push_back(data%MOD);
	}
	reverse(vec.begin(),vec.end());
	ll now=1;
	ll hehe=1;
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=(vec[i]*now)%MOD;
		ans%=MOD;
		now=now*2+hehe;
		now%=MOD;
		hehe*=2;
		hehe%=MOD;
	}
	cout<<ans<<endl;
}
