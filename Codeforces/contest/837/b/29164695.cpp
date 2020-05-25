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
char input[105][105];
char tmp[105][105];
int n,m;
int dp[105][105];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>input[i][j];
		}
	}
	bool ff[256];
	memset(ff,0,sizeof(ff));
	char now=input[0][0];
	bool flag = true;
	for(int i=1;i<n;i++){
		if(input[i][0]!=now){
			flag=false;
			break;
		}
	}
	if(!flag){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				tmp[i][j]=input[j][i];
			}
		}
		swap(n,m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				//cout<<tmp[i][j];
				input[i][j]=tmp[i][j];
			}
			//cout<<endl;
		}
	}
	if(true){
		for(int j=0;j<m;j++){
			char hehe=input[0][j];
			for(int i=1;i<n;i++){
				if(input[i][j]!=hehe){
					cout<<"NO"<<endl;
					exit(0);
				}
			}
		}
		ff[input[0][0]]=true;
		int length=1;
		char hehe=input[0][0];
		int j;
		for(j=1;j<m;j++){
			if(input[0][j]!=hehe){
				break;
			}
			length++;
		}
		hehe=input[0][j];
		if(ff[hehe]){
			cout<<"NO"<<endl;
			exit(0);
		}
		ff[hehe]=true;
		int length2=0;
		for(;j<m;j++){
			if(input[0][j]!=hehe){
				break;
			}
			length2++;
		}
		if(length2!=length){
			cout<<"NO"<<endl;
			exit(0);
		}
		hehe=input[0][j];
		if(ff[hehe]){
			cout<<"NO"<<endl;
			exit(0);
		}
		length2=0;
		ff[hehe]=true;
		for(;j<m;j++){
			if(input[0][j]!=hehe){
				break;
			}
			length2++;
		}
		if(length2!=length){
			cout<<"NO"<<endl;
			exit(0);
		}
		if(j==m){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}


