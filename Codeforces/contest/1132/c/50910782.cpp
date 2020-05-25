#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> vec; 
int mape[5005]={0};
int dp[5005];
int main(){
	int n,q;
	cin>>n>>q;
	int l,r;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		vec.push_back(pii(l,r)); 
		for(int j=l;j<=r;j++){
			mape[j]++; 
		}
	} 
	int ans=-1;
	for(int i=0;i<q;i++){
		l=vec[i].first;
		r=vec[i].second;
		for(int j=l;j<=r;j++){
			mape[j]--;
		}
		dp[0]=0;
		int total=0;
		for(int j=1;j<=n;j++){
			if(mape[j]>0)total++;
			dp[j]=dp[j-1]+(mape[j]==1?1:0);
		}
		int now=INT_MAX;
		for(int j=0;j<q;j++){
			if(j!=i){
				now=min(now,dp[vec[j].second]-dp[vec[j].first-1]);
			}
		}
		for(int j=l;j<=r;j++){
			mape[j]++;
		}
		ans=max(ans,total-now);
	}
	cout<<ans<<endl;
}
