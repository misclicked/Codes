#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	cin>>n;
	vector<int> vec;
	bool flag=true;
	int data;
	cin>>data;
	vec.push_back(data);
	for(int i=1;i<n;i++){
		cin>>data;
		vec.push_back(data);
		if(data!=vec[0]){
			flag=false;
		}
	}
	if(flag){
		cout<<n<<endl;
		exit(0);
	}
	//find break point
	int ans=-1;
	for(int i=0;i<n;i++){
		int zero=0;
		int one=0;
		for(int j=0;j<i;j++){
			if(vec[j])
				one++;
		}
		bool flag2=false;
		for(int j=i;j<n;j++){
			if(vec[j])
				flag2=true;
			if(!vec[j])
				zero++;
		}
		if(!flag2)
			zero=0;
		ans=max(ans,n-one-zero);
	}
	cout<<ans<<endl;
}