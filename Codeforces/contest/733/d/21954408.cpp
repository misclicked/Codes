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
vector<int> vec[100005];
bool cmp(vi a,vi b){
	if(a[0]==b[0]){
		if(a[1]==b[1]){
			return a[2]>b[2];
		}
		return a[1]>b[1];
	}
	return a[0]>b[0];
}
map<int,map<int,vector<pii> > > mape;
int main(){
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n;
	int Max;
	Max=-1;
	int ansk,ansi,ansj;
	ansk=ansi=ansj=0;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		vec[i].push_back(a);
		vec[i].push_back(b);
		vec[i].push_back(c);
		vec[i].push_back(i);
		if(min(a,min(b,c))>Max){
			Max=min(a,min(b,c));
			ansk=1;
			ansi=i;
		}
		stable_sort(vec[i].begin(),vec[i].begin()+3,greater<int>());
		mape[vec[i][0]][vec[i][1]].push_back(pii(vec[i][2],vec[i][3]));
		if(mape[vec[i][0]][vec[i][1]].size()>=2){
			if(mape[vec[i][0]][vec[i][1]].size()==3){
				sort(mape[vec[i][0]][vec[i][1]].begin(),mape[vec[i][0]][vec[i][1]].end(),greater<pii>());
				mape[vec[i][0]][vec[i][1]].pop_back();
			}
			if(min(vec[i][0],min(vec[i][1],mape[vec[i][0]][vec[i][1]][0].first+mape[vec[i][0]][vec[i][1]][1].first))>Max){
				Max=min(vec[i][0],min(vec[i][1],mape[vec[i][0]][vec[i][1]][0].first+mape[vec[i][0]][vec[i][1]][1].first));
				ansk=2;
				ansi=mape[vec[i][0]][vec[i][1]][0].second;
				ansj=mape[vec[i][0]][vec[i][1]][1].second;
				
			}
		}
	}
	/*stable_sort(vec,vec+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}*/
	/*for(int i=0;i<n;){
		int now=vec[i][0];
		if((vec[i][0]==vec[i+1][0])&&(vec[i][1]==vec[i][1]))
			break;		
	}*/
	if(ansk==2){
		cout<<ansk<<endl;
		cout<<ansi+1<<" "<<ansj+1<<endl;
	} else{
		cout<<ansk<<endl;
		cout<<ansi+1<<endl;
	}
}
