#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mape[305][305];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mape[i][j]);
	scanf("%d",&m);
	int a,b,c;
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=mape[i][j];
	for(int t=0;t<m;t++){
		scanf("%d%d%d",&a,&b,&c);
		if(mape[a][b]>c)
			ans=ans-mape[a][b]+c,ans=ans-mape[a][b]+c,mape[a][b]=c,mape[b][a]=c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(mape[i][j]>mape[i][a]+mape[b][j]+c)
					ans=ans-mape[i][j]+mape[i][a]+mape[b][j]+c,mape[i][j]=mape[i][a]+mape[b][j]+c;
				if(mape[i][j]>mape[i][b]+mape[a][j]+c)
					ans=ans-mape[i][j]+mape[i][b]+mape[a][j]+c,mape[i][j]=mape[i][b]+mape[a][j]+c;
			}
		}
		printf("%I64d\n",ans/2);
	}
}
