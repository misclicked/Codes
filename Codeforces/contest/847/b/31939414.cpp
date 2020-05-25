#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long int ll;
int n;
deque<int> fac;
vector<vector<int> > ls;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n;
	int a;
	vector<int> v;
	for(int i=0;i<n;i++)ls.push_back(v);
	for(int i=0;i<n;i++){
		//cout<<">";
		//for(auto it:fac)cout<<it<<" ";
		//cout<<endl;
		cin>>a;
		auto it=upper_bound(fac.begin(),fac.end(),a);
		if(it-fac.begin()>0){
			//cout<<*(it-1)<<endl;
			*(it-1)=a;
			ls[fac.size()-(it-fac.begin())].push_back(a);
		}
		else{
			ls[fac.size()].push_back(a);
			fac.push_front(a);
		}
	}
	for(int i=0;i<fac.size();i++){
		for(auto it:ls[i])cout<<it<<" ";
		cout<<endl;
	}
}
