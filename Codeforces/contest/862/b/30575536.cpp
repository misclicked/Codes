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
vector<vi> vec; 
ll tag[100005];
void DFS(ll now,ll ptag){
	ll ntag=ptag==1?2:1;
	for(ll i=0;i<vec[now].size();i++){
		if(!tag[vec[now][i]]){
			tag[vec[now][i]]=ntag;
			DFS(vec[now][i],ntag);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	ll n;
	cin>>n;
	for(ll i=0;i<=n;i++){
		vi tmp;
		vec.push_back(tmp);
	}
	memset(tag,0,sizeof(tag));
	for(ll i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ll red,blue;
	red=blue=0;
	for(ll i=1;i<=n;i++){
		if(!tag[i]){
			if(red>blue){
				tag[i]=2;
				DFS(i,2);
			}else{
				tag[i]=1;
				DFS(i,1);
			}
		}
		if(tag[i]==1)
			red++;
		else
			blue++;
	}
	cout<<red*blue-(n-1)<<endl;
}


