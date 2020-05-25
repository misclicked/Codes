#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
deque<ll> dq;
int main(){
	ll n,m;
	cin>>n>>m;
	ll ans=LLONG_MAX;
	ll here;
	ll data;
	ll now=0;
	for(int i=0;i<n;i++){
		cin>>data;
		now+=data;
		dq.push_back(data);
		if(dq.size()==m){
			if(ans>now){
				ans=min(ans,now);
				here=(i+1)-m+1;
			}
			now-=dq.front();
			dq.pop_front();
		}
	}
	cout<<here<<endl;
}