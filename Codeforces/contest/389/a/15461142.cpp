#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	vector<ll> vec;
	ll n;
	cin>>n;
	ll data;
	ll MAX=0;
	while(n--){
		cin>>data;
		vec.push_back(data);
		MAX=max(data,MAX);
	}
	bool flag;
	ll ans;
	bool flag2=false;
	for(int i=MAX;i>=2;i--){
		flag=true;
		for(int j=0;j<vec.size();j++){
			if(vec[j]%i!=0){
				flag=false;
				break;
			}
		}
		if(flag){
			flag2=true;
			ans=i*vec.size();
			break;
		}
	}
	if(flag2)
		cout<<ans<<endl;
	else
		cout<<vec.size()<<endl;
}