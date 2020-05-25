#include<bits/stdc++.h>
int dp[200005],i,t,n,p,k,data,ans;
main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&p,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&dp[i]);
		std::sort(dp+1,dp+n+1);
		ans=0;
		for(i=1;i<=n;i++){
			dp[i]+=dp[i>=k?i-k:i-1];
			if(dp[i]<=p)ans=i;
		}
		printf("%d\n",ans);
	}
}