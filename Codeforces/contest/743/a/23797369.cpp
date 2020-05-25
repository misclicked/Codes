#include <bits/stdc++.h>
using namespace std;
 
vector<int> vec;
 
int main() {
	int n,a,b;
	int ans;
	cin>>n>>a>>b;
	vec.push_back(-1);
	getchar();
	for(int i=0;i<n;i++){
		char data;
		data=getchar();
		vec.push_back(data-'0');
	}
	if(vec[a]==vec[b]){
		cout<<0<<endl;
	}else{
		cout<<1<<endl;
	}
	return 0;
}