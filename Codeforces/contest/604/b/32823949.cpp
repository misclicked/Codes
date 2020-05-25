#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,k;
	cin>>n>>k;
	deque<ll> vec;
	vec.resize(n);
	FOR(i,n){
		cin>>vec[i];
	}
	ll now=n;
	ll ans=vec.back();
	if(n-k<=0){
		cout<<ans<<endl;
		exit(0);
	}
	vec.resize((n-k)*2);
	for(int i=0;i<(n-k);i++){
		ans=max(vec[i]+vec[vec.size()-1-i],ans);
	}
	cout<<ans<<endl;
}