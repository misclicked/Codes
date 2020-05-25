#include<bits/stdc++.h>
using namespace std;
typedef pair<int,string> pis;
vector<pis> vec[10005];
map<int,int> mape[10005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m,team,score;
	string name;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>name>>team>>score;
		vec[team].push_back(pis(score,name));
		mape[team][score]++;
	}
	for(int i=1;i<=m;i++)
		sort(vec[i].begin(),vec[i].end(),greater<pis>());
	for(int i=1;i<=m;i++){
		if(mape[i][vec[i][0].first]>2)
			cout<<"?"<<endl;
		else{
			if(mape[i][vec[i][1].first]>1&&mape[i][vec[i][0].first]==1)
				cout<<"?"<<endl;
			else{
				cout<<vec[i][0].second<<" ";
				cout<<vec[i][1].second<<endl;
			}
		}
	}
}