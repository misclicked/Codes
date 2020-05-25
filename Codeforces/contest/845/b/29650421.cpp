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
bool check(string s){
	int a,b;
	a=b=0;
	a=s[0]+s[1]+s[2]-'0'-'0'-'0';
	b=s[3]+s[4]+s[5]-'0'-'0'-'0';
	return a==b;
}
int ans=100;
void dfs(string s, int now, int chg){
	if(check(s)){
		ans=min(ans,chg);
		return;
	}
	if(now==6){
		return;
	}
	for(char c='0';c<='9';c++){
		if(s[now]==c){
			dfs(s,now+1,chg);
		}else{
			string tmp = s;
			tmp[now]=c;
			dfs(tmp,now+1,chg+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	string s;
	cin>>s;
	dfs(s,0,0);
	cout<<ans<<endl;
}


