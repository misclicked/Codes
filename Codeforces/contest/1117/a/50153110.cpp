#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> vec;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll n;
	cin>>n;
	vec.resize(n);
	ll maxe=0;
	for(auto &it:vec){
		cin>>it;
		maxe=max(it,maxe);
	}
	int ans=0;
	int now=0;
	for(int i=0;i<n;i++){
		if(vec[i]==maxe)now++;
		else{
			ans=max(ans,now);
			now=0;
		} 
	}
	ans=max(ans,now);
	cout<<ans<<endl;
}
