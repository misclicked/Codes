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
	ll n,v1,v2,t1,t2;
	cin>>n>>v1>>v2>>t1>>t2;
	ll tot1 = t1*2+v1*n;
	ll tot2 = t2*2+v2*n;
	if(tot1>tot2){
		cout<<"Second"<<endl; 
	}else if(tot1<tot2){
		cout<<"First"<<endl;
	}else
		cout<<"Friendship"<<endl;
}


