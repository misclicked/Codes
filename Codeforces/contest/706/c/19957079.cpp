#include<bits/stdc++.h>
using namespace std;
typedef pair<bool,bool> pbb;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
pss input[100005];
pbb mape[100005];
ll price[100005];
pll dp[100005];
int n;
bool islex(string a,string b){
	int minlen=min(a.length(),b.length());
	for(int i=0;i<minlen;i++){
		if(a[i]<b[i])
			return true;
		if(a[i]>b[i])
			return false;
	}
	return a.length()<=b.length();
}
bool init(){
	string in;
	memset(mape,0,sizeof(mape));
	memset(price,0,sizeof(price));
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>price[i];
	} 
	for(int i=0;i<n;i++){
		cin>>in;
		input[i].first=in;
		reverse(in.begin(),in.end());
		input[i].second=in;
	}
}
ll solve(){
	string temp;
	dp[0].first=0;
	dp[0].second=price[0];
	mape[0].first=true;
	mape[0].second=true;
	ll x1,y1;
	ll x2,y2;
	for(int i=1;i<n;i++){
		x1=x2=y1=y2=LLONG_MAX;
		if(mape[i-1].first){
			if(islex(input[i-1].first,input[i].first)){
				mape[i].first=true;
				x1=dp[i-1].first;
			}
			if(islex(input[i-1].first,input[i].second)){
				mape[i].second=true;
				y1=dp[i-1].first+price[i];
			}
		}
		if(mape[i-1].second){
			if(islex(input[i-1].second,input[i].first)){
				mape[i].first=true;
				x2=dp[i-1].second;
			}
			if(islex(input[i-1].second,input[i].second)){
				mape[i].second=true;
				y2=dp[i-1].second+price[i];
			}
		} 
		if((!mape[i].first)&&(!mape[i].second)){
			return -1;
		}
		dp[i].first=min(x1,x2);
		dp[i].second=min(y1,y2);
	}
	return min(dp[n-1].first,dp[n-1].second);
}
int main(){
	init();
	cout<<solve()<<endl;
}