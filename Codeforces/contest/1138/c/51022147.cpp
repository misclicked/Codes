#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct node{
	int selfs;
	int selfe;
	int south;
	int east;
};
vector<pii> east[1005];
vector<pii> south[1005];
vector<int> temp;
node mape[1005][1005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int data;
			cin>>data;
			east[i].push_back(pii(data,j));
			south[j].push_back(pii(data,i));
		}
	}
	for(int i=0;i<n;i++){
		sort(east[i].begin(),east[i].end());
		int now=1;
		mape[i][east[i][0].second].selfe=now;
		for(int j=1;j<m;j++){
			if(east[i][j-1].first!=east[i][j].first)
				now++;
			mape[i][east[i][j].second].selfe=now;
		}
		for(int j=0;j<m;j++){
			mape[i][east[i][j].second].east=now;
		}
	}
	for(int i=0;i<m;i++){
		sort(south[i].begin(),south[i].end());
		int now=1;
		mape[south[i][0].second][i].selfs=now;
		for(int j=1;j<n;j++){
			if(south[i][j-1].first!=south[i][j].first)
				now++;
			mape[south[i][j].second][i].selfs=now;
		}
		for(int j=0;j<n;j++){
			mape[south[i][j].second][i].south=now;
		}
	}
	for(int i=0;i<n;i++){
		if(mape[i][0].selfe>mape[i][0].selfs){
			mape[i][0].south+=mape[i][0].selfe-mape[i][0].selfs;
		}else if(mape[i][0].selfe<mape[i][0].selfs){
			mape[i][0].east+=mape[i][0].selfs-mape[i][0].selfe;
		}
		cout<<max(mape[i][0].east,mape[i][0].south);
		for(int j=1;j<m;j++){
			if(mape[i][j].selfe>mape[i][j].selfs){
				mape[i][j].south+=mape[i][j].selfe-mape[i][j].selfs;
			}else if(mape[i][j].selfe<mape[i][j].selfs){
				mape[i][j].east+=mape[i][j].selfs-mape[i][j].selfe;
			}
			cout<<" "<<max(mape[i][j].east,mape[i][j].south);
		}
		cout<<endl;
	}
}