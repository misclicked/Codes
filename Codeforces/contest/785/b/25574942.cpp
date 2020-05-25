#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool compare(pii a, pii b){
	return a.second<b.second;
}
int main(){
	int n,m,a,b;
	cin>>n;
	vector<pii> vec;
	vector<pii> vec2;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		vec.push_back(pii(a,b));
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		vec2.push_back(pii(a,b));
	}
	int ans = 0;
	//case 1 n before m;
	sort(vec.begin(),vec.end(),compare);
	sort(vec2.begin(),vec2.end(),greater<pii>());
	ans = max(ans,vec2[0].first-vec[0].second);
	//case 2 n after m;
	sort(vec2.begin(),vec2.end(),compare);
	sort(vec.begin(),vec.end(),greater<pii>());
	ans = max(ans,vec[0].first-vec2[0].second);
	cout<<ans<<endl;
}