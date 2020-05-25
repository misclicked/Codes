#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	int n,m;
	set<int> sol;
	cin>>n>>m;
	int left,right,ans=0;
	char data;
	bool flag=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>data;
			if(data=='G')
				left=j;
			else if(data=='S')
				right=j;
		}
		if(right<left)
			flag=true;
		sol.insert(right-left);
	}
	if(flag){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<sol.size()<<endl;
	return 0;
}