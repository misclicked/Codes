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
bool compare(pii a, pii b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	cin>>n;
	vii vec;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		vec.push_back(pii(a,1));
		vec.push_back(pii(b,-1));
	}
	int now=0;
	sort(vec.begin(),vec.end(),compare);
	/*for(int i=0;i<n*2;i++){
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}*/
	for(int i=0;i<n*2;i++){
		now+=vec[i].second;
		if(now>2){
			cout<<"NO"<<endl;
			return 0; 
		}
	}
	cout<<"YES"<<endl;
}


