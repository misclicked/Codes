#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[100005]={0};
int main(){
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1])
			dp[i]=1;
	}
	for(int i=1;i<s.size();i++){
		dp[i]+=dp[i-1];
	}
	int n;
	cin>>n;
	int l,r;
	while(n--){
		cin>>l>>r;l--;r--;
		cout<<dp[r]-dp[l]<<endl;
	}
}
