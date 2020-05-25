#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mypow(ll a,ll b){
	int x=1,r=b;
	while(a){
		if(a%2)
			x*=b;
		b*=b;
		a/=2;
	}
	return x;
}
int main(){
	int n;
	cin>>n;
	int cnt=0;
	ll ans=1;
	int data;
	bool flag=false;
	for(int i=0;i<n;i++){
		cin>>data;
		if(data&&!flag)
			flag=true;
		else if(data&&flag){
			ans*=cnt+1;
			cnt=0;
		}
		if(!data&&flag)cnt++;
	}
	if(!flag)
		cout<<0<<endl;
	else
		cout<<ans<<endl;
}