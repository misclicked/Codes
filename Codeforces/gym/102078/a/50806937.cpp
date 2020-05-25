#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
int main(){
	ll n,total=0;
	cin>>n;
	vec.resize(n);
	for(auto &it:vec){
		cin>>it;
		total+=it;
	}
	sort(vec.begin(),vec.end(),greater<ll>());
	ll q;
	cin>>q;
	while(q--){
		int input;
		cin>>input;
		cout<<total-vec[input-1]<<endl;
	}
}