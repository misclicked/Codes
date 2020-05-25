#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mape[305][305];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mape[i][j];
		}
	}
	int m;
	cin>>m;
	for(int t=0;t<m;t++){
		int a,b,c;
		cin>>a>>b>>c;
		if(mape[a][b]>c){
			mape[a][b]=c;
			mape[b][a]=c;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mape[i][j]>mape[i][a]+mape[b][j]+c){
					mape[i][j]=mape[i][a]+mape[b][j]+c;
				}
				if(mape[i][j]>mape[i][b]+mape[a][j]+c){
					mape[i][j]=mape[i][b]+mape[a][j]+c;
				}
			}
		}
		ll ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=mape[i][j];
		cout<<ans<<endl;	
	}
}
