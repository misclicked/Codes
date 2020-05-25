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
	int mape[256];
	mape['^']=0;
	mape['>']=1;
	mape['v']=2;
	mape['<']=3;
	char mape2[256];
	mape2[0]='^';
	mape2[1]='>';
	mape2[2]='v';
	mape2[3]='<';
	char a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	bool cw = mape2[(mape[a]+n)%4]==b;
	bool ccw = mape2[((mape[a]-n)%4+4)%4]==b;
	if(cw&&ccw||((!cw)&&(!ccw))){
		cout<<"undefined"<<endl;
	}else if(cw){
		cout<<"cw"<<endl;
	}else
		cout<<"ccw"<<endl;
}


