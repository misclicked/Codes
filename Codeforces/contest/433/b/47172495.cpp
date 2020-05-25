#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll dp1[100005]={0};
ll dp2[100005]={0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> vec;
	int n;
	cin>>n;
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	for(int i=1;i<=n;i++){
		dp1[i]=dp1[i-1]+vec[i-1];
	}
	sort(vec.begin(),vec.end());
	for(int i=1;i<=n;i++){
		dp2[i]=dp2[i-1]+vec[i-1];
	}
	int t;
	cin>>t;
	while(t--){
		ll type,l,r;
		cin>>type>>l>>r;
		if(type==1){
			cout<<dp1[r]-dp1[l-1]<<endl; 
		}
		if(type==2){
			cout<<dp2[r]-dp2[l-1]<<endl; 
		}
	}
}
