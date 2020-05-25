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
vector<int> vec;
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
		vec.clear();
		int a,b,c;
		cin>>a>>b>>c;
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
		vec.push_back(i);
		if(min(a,min(b,c))>Max){
			Max=min(a,min(b,c));
			ansk=1;
			ansi=i;
		}
		stable_sort(vec.begin(),vec.begin()+3,greater<int>());
		mape[vec[0]][vec[1]].push_back(pii(vec[2],vec[3]));
		if(mape[vec[0]][vec[1]].size()>=2){
			if(mape[vec[0]][vec[1]].size()==3){
				sort(mape[vec[0]][vec[1]].begin(),mape[vec[0]][vec[1]].end(),greater<pii>());
				mape[vec[0]][vec[1]].pop_back();
			}
			if(min(vec[0],min(vec[1],mape[vec[0]][vec[1]][0].first+mape[vec[0]][vec[1]][1].first))>Max){
				Max=min(vec[0],min(vec[1],mape[vec[0]][vec[1]][0].first+mape[vec[0]][vec[1]][1].first));
				ansk=2;
				ansi=mape[vec[0]][vec[1]][0].second;
				ansj=mape[vec[0]][vec[1]][1].second;
			}
		}
	}
	if(ansk==2){
		cout<<ansk<<endl;
		cout<<ansi+1<<" "<<ansj+1<<endl;
	} else{
		cout<<ansk<<endl;
		cout<<ansi+1<<endl;
	}
}
