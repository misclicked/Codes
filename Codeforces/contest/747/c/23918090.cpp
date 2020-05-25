#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll n,q,nowt;
set<ll> nowfree;
priority_queue<pll,vector<pll>,greater<pll>> pq;
int main(){
	nowfree.clear();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		nowfree.insert(i);
	}
	ll t,k,d;
	for(int i=0;i<q;i++){
		cin>>t>>k>>d;
		while(pq.size()&&pq.top().first<=t){
			nowfree.insert(pq.top().second);
			pq.pop();
		}
		if(nowfree.size()>=k){
			int cnt=0,sum=0;
			vector<int> todel;
			auto it = nowfree.begin();
			for(auto it:nowfree){
				pq.push(pll(t+d,it));
				cnt++;
				sum+=it;
				todel.push_back(it);
				if(cnt==k)
					break;
			}
			for(auto it:todel){
				nowfree.erase(it);
			}
			cout<<sum<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
}