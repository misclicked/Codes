#include<bits/stdc++.h>
#define N 200000
using namespace std;
typedef long long ll;
int mape[505][505];
bool np[N];
vector<int> primes;
void build(){
	memset(np,0,sizeof(np));
	np[0]=1;np[1]=1;
	for(int i=2;i<N;i++){
		if(!np[i])primes.push_back(i);
		for(int k:primes){
			if(i*k>=N)break;
			np[i*k]=1;
			if(i%k==0)break;
		}
	}
}
int nextprime(int a){
	return *lower_bound(primes.begin(),primes.end(),a);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	build();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mape[i][j];
		}
	}
	ll ans=LLONG_MAX;
	for(int i=0;i<n;i++){
		ll now=0;
		for(int j=0;j<m;j++){
			now+=nextprime(mape[i][j])-mape[i][j];
		}
		ans=min(now,ans);
	}
	for(int i=0;i<m;i++){
		ll now=0;
		for(int j=0;j<n;j++){
			now+=nextprime(mape[j][i])-mape[j][i];
		}
		ans=min(now,ans);
	}
	cout<<ans<<endl;
}
