#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> vec;
int main(){
	cin>>n;
	ll data;
	vec.clear();
	for(int i=0;i<n;i++){
		cin>>data;
		vec.push_back(data);
	}
	sort(vec.begin(),vec.end());
	ll now=1;
	ll step=0;
	for(int i=0;i<n;i++){
		if(vec[i]!=now)
			step+=abs(now-vec[i]);
		now++;
	}
	cout<<step<<endl;
}