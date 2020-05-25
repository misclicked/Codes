#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mape[100005];
ll sol[100005];
int main(){
	ios_base::sync_with_stdio(false);
	ll n,input;
	cin>>n;
	memset(mape,0,sizeof(mape));
	for(ll i=0;i<n;i++){
		cin>>input;
		mape[input]++;
	}
	cin>>n;
	memset(sol,0,sizeof(sol));
	ll cnt=0;
	for(ll i=1;i<=100000;i++){
		if(mape[i]){
			cnt+=mape[i];
		}
		sol[i]=cnt;
	}
	int now;
	for(ll i=0;i<n;i++){
		cin>>input;
		if(input>=100000)
			cout<<sol[100000]<<endl;
		else
			cout<<sol[input]<<endl;
	}
}