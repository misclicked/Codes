#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,p;
ll cnt(ll n){
	ll tmp=n;
	while(tmp){
		n=n*10+tmp%10;
		tmp/=10;
	} 
	return n;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>k>>p;
	ll ans=0;
	for(ll i=1;i<=k;i++){
		ans+=cnt(i)%p;
	}
	cout<<ans%p<<endl;
}
