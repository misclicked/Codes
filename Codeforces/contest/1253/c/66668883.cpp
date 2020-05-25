#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
long long int dp[200005]={0}; 
int main(){
	int n,m;
	cin>>n>>m;
	vec.resize(n);
	for(auto &it: vec)
		scanf("%d",&it);
	sort(vec.begin(),vec.end());
	for(int i=1;i<=n;i++)
		printf("%I64d ",dp[i]=(i<=m?(vec[i-1]+dp[i-1]):dp[i-1]+dp[i-m]-dp[i-m-1]+vec[i-1]));
	puts("");
}