#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> vec;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		vec.push_back(data);
	}
	sort(vec.begin(),vec.end(),greater<ll>());
	ll rows=m/(k+1);
	ll remain=m%(k+1);
	ll rowsValue=vec[0]*k+vec[1];
	ll ans=rowsValue*rows+remain*vec[0];
	cout<<ans<<endl;
}
