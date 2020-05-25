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
	int n;
	cin>>n;
	bool canotk=true;
	int nowspd;
	int nowlmt=INT_MAX;
	int nowotksign=0;
	int ans=0;
	stack<int> lmtsigns;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		switch(data){
			case 1:{
				cin>>data;
				nowspd=data;
				while(lmtsigns.size()&&nowspd>lmtsigns.top()){
					ans++;
					lmtsigns.pop();
				}
				break;
			}
			case 2:{
				ans+=nowotksign;
				nowotksign=0;
				break;
			}
			case 3:{
				cin>>data;
				nowlmt=data;
				lmtsigns.push(data);
				while(lmtsigns.size()&&nowspd>lmtsigns.top()){
					ans++;
					lmtsigns.pop();
				}
				break;
			}
			case 4:{
				nowotksign=0;
				break;
			}
			case 5:{
				nowlmt=INT_MAX;
				while(lmtsigns.size()){
					lmtsigns.pop();
				}
				break;
			}
			case 6:{
				nowotksign++;
				break;
			}
		}
	} 
	cout<<ans<<endl;
}


