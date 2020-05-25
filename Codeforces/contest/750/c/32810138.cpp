#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> vec;
bool can(ll n){
	ll now;
	for(int i=0;i<vec.size();i++){
		n-=vec[i].first;
		if(n>=1900)now=1;
		else now=2;
		if(now!=vec[i].second)return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	ll n;
	cin>>n;
	vec.resize(n);
	FOR(i,n)cin>>vec[i].first>>vec[i].second;
	//check Infinity
	bool contain2=false;
	FOR(i,n){
		if(vec[i].second==2)contain2=true;
	}
	if(!contain2){
		cout<<"Infinity"<<endl;
		exit(0);
	}
	ll bordermax=LLONG_MIN;
	ll bordermin=LLONG_MAX;
	ll now=0;
	FOR(i,n){
		if(vec[i].second==1){
			bordermin=min(bordermin,now);
		}
		if(vec[i].second==2){
			bordermax=max(bordermax,now);
		}
		now+=vec[i].first;
	}
	if(bordermax>=bordermin){
		cout<<"Impossible"<<endl;
		exit(0);
	}
	cout<<1899-bordermax+now<<endl;
}
