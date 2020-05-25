#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> bike;
vector<ll> boy;
ll n,m,a,hehe;
bool can(ll mid){
	ll need=0;
	//cout<<mid<<endl;
	for(int i=0;i<mid;i++){
		//cout<<bike[i]<<" "<<boy[n-mid+i]<<endl;
		if(bike[i]>boy[n-mid+i]){
			need+=(bike[i]-boy[n-mid+i]);
		}
	}
	//cout<<need<<endl;
	return need<=a;
}
int main(){
	bike.clear();boy.clear();
	cin>>n>>m>>a;
	ll data;
	for(int i=0;i<n;i++){
		cin>>data;
		boy.push_back(data);
	}
	for(int i=0;i<m;i++){
		cin>>data;
		bike.push_back(data);
	}
	sort(boy.begin(),boy.end());
	sort(bike.begin(),bike.end());
	ll l,r,mid;
	l=0,r=min(n,m);
	ll ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(can(mid)){
			ans=max(mid,ans);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<" ";
	if(ans==0){
		cout<<0<<endl;
		return 0;
	}
	hehe=0;
	ll haha=0;
	for(int i=0;i<ans;i++){
		if(bike[i]>boy[n-ans+i]){
			hehe+=boy[n-ans+i];
			haha+=bike[i]-boy[n-ans+i];
		}else{
			hehe+=bike[i];
		}
	}
	haha-=a;
	if((hehe+haha)<0)
		cout<<0<<endl;
	else
		cout<<hehe+haha<<endl;
}