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
	ll n;
	cin>>n;
	if(n==0){
		cout<<1<<endl;
		return 0;
	} 
	if(n%4==1)
		cout<<8<<endl;
	if(n%4==2)
		cout<<4<<endl;
	if(n%4==3)
		cout<<2<<endl;
	if(n%4==0)
		cout<<6<<endl;
}

