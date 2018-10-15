#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll input[100005];
ll n,m,M;
bool check(ll now){
	ll i,tmp,here;
	here=input[0];
	for(i=0;i<n;){
		if(m==0)
			break;
		tmp=now;
		tmp-=(i+1);
		while(tmp>0){
			if(tmp>=here){
				tmp-=here;
				here=input[++i];
				if(i==n){
					here=0;
					break;
				}
				tmp--;
			}else{
				here-=tmp;
				break;
			}
		}
		m--;
	}
	if(here>0)
		return false;
	if(i==n-1&&here==0)
		return true;
	if(here==0){
		for(;i<n;i++){
			if(input[i]>0)
				return false;
		}
	}
	return true;
}
int main(){
	ll sum=0;
	cin>>n>>M;
	memset(input,0,sizeof(input));
	for(int i=0;i<n;i++){
		cin>>input[i];	
	}
	ll l=0,mid;
	ll r=LLONG_MAX-l;
	ll ans=-1;
	while(l<=r){
		m=M; 
		mid=(l+r)/2;
		if(mid<0)cout<<"bug"<<endl; 
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	} 
	cout<<ans<<endl;
}