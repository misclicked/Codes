#include<bits/stdc++.h>
using namespace std;
map<int,bool> mape;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int data;
		cin>>data;
		mape[data]=true;
	}
	int now=1;
	int l,r;
	if(mape[now]){
		cout<<now<<endl;
		return 0;
	}
	for(int i=0;i<k;i++){
		cin>>l>>r;
		if(l==now)
			now=r;
		else if(r==now)
			now=l;
		if(mape[now]){
			break;
		}
	}
	cout<<now<<endl;
}