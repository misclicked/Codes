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
pii input[105];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>input[i].first>>input[i].second;
	}
	ll ans=0;
	for(int i=0;i<n-1;i++){
		int x1 = input[i].first;
		int y1 = input[i].second;
		if(!(x1>a||y1>b)){
			for(int j=i+1;j<n;j++){
				int x2 = input[j].first;
				int y2 = input[j].second;
				if(!(x2>a||y2>b)){
					if((x1+x2)<=a||(y1+y2)<=b){
						ans=max(ans,(x1*y1*1LL)+(x2*y2*1LL));
					}
				} 
				x2 = input[j].second;
				y2 = input[j].first;
				if(!(x2>a||y2>b)){
					if((x1+x2)<=a||(y1+y2)<=b){
						ans=max(ans,(x1*y1*1LL)+(x2*y2*1LL));
					}
				} 
			}
		}
		
		x1 = input[i].second;
		y1 = input[i].first;
		if(!(x1>a||y1>b)){
			for(int j=i+1;j<n;j++){
				int x2 = input[j].first;
				int y2 = input[j].second;
				if(!(x2>a||y2>b)){
					if((x1+x2)<=a||(y1+y2)<=b){
						ans=max(ans,(x1*y1*1LL)+(x2*y2*1LL));
					}
				} 
				x2 = input[j].second;
				y2 = input[j].first;
				if(!(x2>a||y2>b)){
					if((x1+x2)<=a||(y1+y2)<=b){
						ans=max(ans,(x1*y1*1LL)+(x2*y2*1LL));
					}
				} 
			}
		} 
	}
	cout<<ans<<endl;
}


