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
template<class T>
class disjoint_set{
	public:
		int *arr;
		int *member;
		int N, groups;
		disjoint_set(int N){
			this->N = N;
			arr = new int[N+5];
			member = new int[N+5];
		}
		void init(){
			for(int i=0;i<=N;i++){
				arr[i] = i;
				member[i] = 1;
			}
			groups = N;
		}
		int find(int x){
			return x == arr[x] ? x : (arr[x] = find(arr[x]));
		}
		void uni(int x,int y){
			x = find(x); y = find(y);
			if(x==y)	return;
			groups--;
			member[y] += member[x];
			member[x] = 0;
			arr[x] = y;
		}
		bool isgroup(int x,int y){
			return find(x) == find(y);
		}
		int cardinality(int x){
			return member[find(x)];
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,k;
	cin>>n>>k;
	ll Min,Max;
	Min=1e9+5;
	Max=-1e9-5;
	ll data;
	vector<ll> vec;
	for(int i=0;i<n;i++){
		cin>>data;
		Min=min(Min,data);
		Max=max(Max,data);
		vec.push_back(data);
	}
	if(k==1){
		cout<<Min<<endl;
	}else if(k>2){
		cout<<Max<<endl;
	}else{
		ll ml,mr;
		ml=vec[0];
		mr=vec[n-1];
		int l,r;
		l=1,r=1;
		while((l+r)!=n){
			if(ml<mr){
				l++;
				ml=min(ml,vec[l-1]);
			}else{
				r++;
				mr=min(mr,vec[n-r]); 
			}
		}
		cout<<max(ml,mr)<<endl;
	}
}


