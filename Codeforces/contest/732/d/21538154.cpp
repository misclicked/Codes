#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<ll> vec;
int main(){
	priority_queue<ll,vector<ll>,greater<ll> > que;
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll data;
		cin>>data;
		vec.push_back(data);
	}
	for(int i=0;i<m;i++){
		ll data;
		cin>>data;
		que.push(data);
	}
	ll cnt=0;
	ll pass=0;
	for(int i=0;i<n;i++){
		//cout<<i<<endl;
		//cout<<i<<" "<<pass<<" "<<que.top()<<endl; 
		if(vec[i]!=0){
			if(cnt){
				if(vec[i]>cnt){
					pass+=cnt;
					cnt=0;
				}else{
					pass+=vec[i];
					cnt-=vec[i];
				}
			}else{
				if(!que.empty()){
					ll tmp=que.top();
					que.pop();
					que.push(tmp-1);
				}
			}
		}else{
			if(!que.empty()){
				ll tmp=que.top();
				que.pop();
				que.push(tmp-1);
			}
		}
		if(!que.empty()){
			while(!que.empty()&&que.top()==0){
				que.pop();
				cnt++;
			}
		}
		if(pass==m){
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}