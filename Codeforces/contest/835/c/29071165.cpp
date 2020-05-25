#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,char> pic;
typedef vector<pic> vpic;
typedef vector<pll> vll;
vector<int> mape[105][105];
int ans[15][105][105];
ll n,m,c;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m>>c;
	memset(ans,0,sizeof(ans));
	for(ll i=0;i<n;i++){
		ll aa,bb,cc;
		cin>>aa>>bb>>cc;
		mape[aa][bb].push_back(cc);
	}
	for(ll nn=0;nn<=11;nn++){
		for(ll i=0;i<=100;i++){
			for(ll j=0;j<=100;j++){
				ll tot=0;
				for(auto it:mape[i][j]){
					tot+=(it+nn)%(c+1);
				}
				ans[nn][i][j] = tot;
			}
		}
		for(ll i=0;i<=101;i++){
			for(ll j=1;j<=101;j++){
				ans[nn][i][j]=ans[nn][i][j]+ans[nn][i][j-1];
				if(ans[nn][i][j]){
					//cout<<ans[nn][i][j]<<endl;
				}
			}
		}
	}
	for(ll i=0;i<m;i++){
		ll aa,bb,cc,dd,ee;
		ll now=0;
		cin>>aa>>bb>>cc>>dd>>ee;
		aa=aa%(c+1);
		/*for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				cout<<ans[aa][i][j];
			}
			cout<<endl;
		}*/
		for(ll i=bb;i<=dd;i++){
			//cout<<ans[aa][i][cc-1]<<" "<<ans[aa][i][ee-1]<<endl;
			if(cc-2<0){
				now+=ans[aa][i][ee];
			}else
				now+=ans[aa][i][ee]-ans[aa][i][cc-1];
		}
		cout<<now<<endl;
	}
}


