#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector<int> m;
	cin>>n;
	int data;
	int box=0;
	while(n--){
		cin>>data;
		m.push_back(data);
	}
	int ans=0;
	sort(m.begin(),m.end());
	bool flag=true;
	while(flag){
		flag=false;
		int now=0;
		for(int i=0;i<m.size();i++){
			if(m[i]>=now){
				flag=true;
				now++;
				m[i]=-1;
			}
		}
		if(flag)ans++;
	}
	cout<<ans<<endl;
}