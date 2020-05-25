#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b;
ll n,m,p;
ll Get(ll idx){
	ll ans=0;
	for(int i=0;i<n;i++){
		if(idx-i>=0&&idx-i<m){
			//cout<<a[i]<<" "<<b[idx-i]<<endl;
			ans+=a[i]*b[idx-i];
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m>>p;
	a.resize(n);
	b.resize(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int ai,bi;
	for(int i=0;i<n;i++){
		if(__gcd(a[i],p)==1){
			ai=i;break;
		}
	}
	for(int i=0;i<m;i++){
		if(__gcd(b[i],p)==1){
			bi=i;break;
		}
	}
	cout<<ai+bi<<endl;
}