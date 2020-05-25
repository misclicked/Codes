#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
class disjoll_set{
	public:
		ll *arr;
		ll *member;
		ll N, groups;
		disjoll_set(ll N){
			this->N = N;
			arr = new ll[N+5];
			member = new ll[N+5];
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
			arr[x] = y;
		}
		bool isgroup(ll x,ll y){
			return find(x) == find(y);
		}
		ll cardinality(ll x){
			return member[find(x)];
		}
};
map<ll,ll> mape;
vector<ll> vec;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	ll n,x;
	cin>>n>>x;
	ll data;
	vec.clear();
	for(ll i=0;i<n;i++){
		cin>>data;
		vec.push_back(data);
		mape[data]++;
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		if(mape[(vec[i]^x)]&&mape[vec[i]]){
			if((vec[i]^x)==vec[i])
				ans+=(mape[vec[i]]-1)*(mape[vec[i]])/2;
			else
				ans+=mape[(vec[i]^x)]*mape[vec[i]];
			mape[(vec[i]^x)]=mape[vec[i]]=0;
		}
	}
	cout<<ans<<endl;
}