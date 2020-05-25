#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<class T>
class disjoll_set{
	public:
		ll *arr;
		ll *member;
		ll *weight;
		ll *bea;
		ll N, groups;
		disjoll_set(ll N){
			this->N = N;
			arr = new ll[N+5];
			member = new ll[N+5];
			weight = new ll[N+5];
			bea = new ll[N+5];
		}
		void init(){
			for(ll i=0;i<=N;i++){
				arr[i] = i;
				member[i] = 1;
			}
			groups = N;
		}
		ll find(ll x){
			return x == arr[x] ? x : (arr[x] = find(arr[x]));
		}
		void uni(ll x,ll y){
			x = find(x); y = find(y);
			if(x==y)	return;
			groups--;
			member[y] += member[x];
			member[x] = 0;
			weight[y] += weight[x];
			weight[x] = 0;
			bea[y] += bea[x];
			bea[x] = 0;
			arr[x] = y;
		}
		bool isgroup(ll x,ll y){
			return find(x) == find(y);
		}
		ll cardinality(ll x){
			return member[find(x)];
		}
};
ll orgbea[1005];
ll orgwei[1005];
vector<vector<pll> > vec(1005); 
pll here[1005];
ll dp[1005];
int main(){
	ll n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	disjoll_set<ll> dj(n);
	dj.init();
	for(ll i=1;i<=n;i++){
		scanf("%I64d",&dj.weight[i]);
		orgwei[i]=dj.weight[i];
	}
	for(ll i=1;i<=n;i++){
		scanf("%I64d",&dj.bea[i]);
		orgbea[i]=dj.bea[i];
	}
	while(m--){
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		dj.uni(a,b);
		dj.uni(b,a);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		vec[dj.find((i))].push_back(pll(orgbea[i],orgwei[i]));
	}
	vector<ll> decided;
	for(ll i=1;i<=n;i++){
		if(vec[i].size()!=0){
			ll tmp=0;
			ll tmpweight=0;
			for(int j=0;j<vec[i].size();j++){
				tmpweight+=vec[i][j].second;
				tmp+=vec[i][j].first;	
			}
			vec[i].push_back(pll(tmp,tmpweight));
			decided.push_back(i);	
		}
	}
	memset(dp,0,sizeof(dp));
	for(ll r=0;r<decided.size();r++){
		for(ll j=k;j>=0;j--)
			for(ll i=0;i<vec[decided[r]].size();i++)
				if((j-vec[decided[r]][i].second)>=0)
					dp[j]=max(dp[j],dp[j-vec[decided[r]][i].second]+vec[decided[r]][i].first);
	}
	ans=max(ans,dp[k]);
	printf("%I64d\n",ans);
}


