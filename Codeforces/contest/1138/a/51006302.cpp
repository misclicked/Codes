#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
	int n,one,two;
	cin>>n;
	int ans=0;
	one=two=0;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		if(data==1){
			one++;
			if(two){
				vec.push_back(two);
				two=0;
			}
		}else{
			two++;
			if(one){
				vec.push_back(one);
				one=0;
			}
		}
	}
	if(two){
		vec.push_back(two);
		two=0;
	}
	if(one){
		vec.push_back(one);
		one=0;
	}
	for(int i=0;i<vec.size()-1;i++){
		ans=max(ans,min(vec[i],vec[i+1]));
	}
	cout<<ans*2<<endl;
} 