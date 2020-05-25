#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,char> pic;
typedef pair<double,int> pdi;
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
	ll n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int opened=0;
	bool YES=false;
	map<char,int> in;
	map<char,int> out;
	for(char c='A';c<='Z';c++){
		in[c]=n+1;
		out[c]=-1;
	}
	for(int i=0;i<s.length();i++){
		in[s[i]]=min(in[s[i]],i);
		out[s[i]]=max(out[s[i]],i);
	}
	vi vin,vout;
	vector<pdi> vec;
	for(char c='A';c<='Z';c++){
		if(in[c]!=n+1){
			vec.push_back(pdi(in[c],1));
		}
		if(out[c]!=-1){
			vec.push_back(pdi(out[c]+0.5,-1));
		}
	}
	sort(vec.begin(),vec.end());
	int now=0;
	for(int i=0;i<vec.size();i++){
		now+=vec[i].second;
		if(now>m){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}


