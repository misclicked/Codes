#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	ll data;
	vector<ll> vec;
	vec.push_back(0);
	for(ll i=1;i<=4;i++){
		cin>>data;
		vec.push_back(data);
	}
	string input;
	getchar();
	getline(cin,input);
	istringstream ss(input);
	char c;
	ll ans=0;
	while(ss>>c){
		ans+=vec[c-'0'];
	}
	cout<<ans<<endl;
}