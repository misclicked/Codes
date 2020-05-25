#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ans[600005];
int dp[600005];
ll calc(ll n){
	return (n*(n+1))/2;
}
ll n=0,k=0;
int main(){
	/*cout<<fixed<<(ll)1e18*2LL<<endl;
	cout<<LLONG_MAX<<endl;
	cout<<sqrt((ll)1e18*2LL)<<endl;*/
	memset(dp,0,sizeof(dp));
	srand(time(0));
	scanf("%I64d%I64d",&n,&k);
	if(k>(n*(n-1))/2){
		puts("Impossible");
		return 0;
	}
	n=n*2;
	ll cnt=0;
	ll base=sqrt(k)-1;
	while(calc(base+1)<=k){
		base++;
	}
	//cout<<base<<endl;
	//system("pause");
	ll now=base;
	k-=calc(base);
	while(now){
		//cout<<k<<" "<<now<<" "<<k/now<<endl;
		dp[now]=k/now;
		k=k%now;
		now--;
	}
	dp[base]++;
	/*for(int i=0;i<base;i++)
		cout<<dp[i]<<endl;*/
	for(int i=1;i<=base;i++){
		ans[cnt++]='(';
		//cout<<i<<" "<<dp[i]<<endl;
		for(int j=0;j<dp[i];j++){
			ans[cnt++]='(';
			ans[cnt++]=')';
		}
	}
	for(int i=base-1;i>=0;i--){
		ans[cnt++]=')';
	}
	while(cnt!=n){
		ans[cnt++]='(';
		ans[cnt++]=')';
	}
	puts(ans);
}