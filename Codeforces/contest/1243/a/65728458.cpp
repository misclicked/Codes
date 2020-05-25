#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	int n;
	vector<int> vec;
	while(k--){
		cin>>n;
		vec.resize(n);
		for(int i=0;i<n;i++){
			cin>>vec[i];
		}
		sort(vec.begin(),vec.end(),greater<int>());
		int ans=1;
		for(int i=0;i<n;i++){
			ans=max(ans,min(i+1,vec[i]));
		}
		cout<<ans<<endl;
	}
} 