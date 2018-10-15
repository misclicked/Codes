#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,s,c,pb,ps,pc,nb,ns,nc,r;
bool can(ll n){
	ll money=0;
	if(n*nb-b>0)money+=(n*nb-b)*pb;
	if(n*ns-s>0)money+=(n*ns-s)*ps;
	if(n*nc-c>0)money+=(n*nc-c)*pc;
	return money<=r;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	string a;
	cin>>a;
	cin>>b>>s>>c>>pb>>ps>>pc>>r;
	nb=ns=nc=0;
	for(int i=0;i<a.size();i++){
		switch(a[i]){
			case 'B':{
				nb++;
				break;
			}
			case 'S':{
				ns++;
				break;
			}
			case 'C':{
				nc++;
				break;
			}
		}
	}
	ll l=0,r=(ll)1e13,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(can(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
}
