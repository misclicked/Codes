#include<bits/stdc++.h>
using namespace std;
map<vector<int>,vector<int> > mape;
unordered_map<int, vector<int> > input;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n;
	cin>>n;
	if(n==2){
		int m;
		cin>>m;
		vector<int> vec1,vec2;
		for(int i=0;i<m/2;i++){
			int data;
			cin>>data;
			vec1.push_back(data);
		}
		for(int i=m/2;i<m;i++){
			int data;
			cin>>data;
			vec2.push_back(data);
		}
		cout<<m/2;
		for(auto it:vec1){
			cout<<" "<<it;
		}
		cout<<endl;
		cout<<m/2;
		for(auto it:vec2){
			cout<<" "<<it;
		}
		cout<<endl;
		return 0;
	} 
	for(int i=0;i<(n*(n-1))/2;i++){
		int m;
		cin>>m;
		vector<int> vec;
		for(int j=0;j<m;j++){
			int data;
			cin>>data;
			input[data].push_back(i);
		}
	}
	for(auto it:input){
		mape[it.second].push_back(it.first);
	}
	for(auto it:mape){
		cout<<it.second.size();
		for(auto it2:it.second){
			cout<<" "<<it2;
		}
		cout<<endl;
	}
} 