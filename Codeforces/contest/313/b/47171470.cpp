#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int dp[100005]={0};
int main(){
	char pre,now;
	pre=getchar();
	for(int i=1;(now=getchar())!='\n';i++){
		if(pre==now)
			dp[i]=1;
		pre=now;
		dp[i]+=dp[i-1];
	}
	int n;
	scanf("%d",&n);
	int l,r;
	while(n--){
		scanf("%d %d",&l,&r);
		l--;r--;
		printf("%d\n",dp[r]-dp[l]);
	}
}
