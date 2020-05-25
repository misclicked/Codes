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
int now,N;
int dis[105][105];
int ans[105];
vector<int> vec(105);
void dfs(int n,int dep){
	if(dis[now][n])
		return;
	dis[now][n]=dep+1;
	dfs(vec[n],dep+1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	memset(dis,0,sizeof(dis));
	memset(ans,0,sizeof(ans));
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>vec[i];
	}
	for(int i=1;i<=N;i++){
		now=i;
		dfs(vec[i],0);
	}
	/*for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int ANS=1;
	for(int i=1;i<=N;i++){
		if(dis[i][i]==dis[i][i]){
			if(dis[i][i]){
				if(dis[i][i]%2==0)
					dis[i][i]/=2;
				ANS*=(dis[i][i]/__gcd(dis[i][i],ANS));
				ans[i]=true;
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(!ans[i]){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	cout<<ANS<<endl;
}