#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007ll
ll dp[100005]={1,1};
int main(){
	for(int i=2;i<100005;i++){
		dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}
	string s;
	cin>>s;
	ll u,n;
	u=n=0;
	ll ans=1;
	s.push_back('^');
	for(char c:s){
		switch(c){
			case 'u':
				if(n){
					ans*=dp[n];
					ans=ans%MOD;
					u=n=0;
				}
				u++;
				break;
			case 'n':
				if(u){
					ans*=dp[u];
					ans=ans%MOD;
					u=n=0;
				}
				n++;
				break;
			case 'm':
			case 'w':
				ans*=0;
			default:
				if(u)ans*=dp[u];
				if(n)ans*=dp[n];
				ans=ans%MOD;
				u=n=0;
		}
	}
	cout<<ans<<endl;
}