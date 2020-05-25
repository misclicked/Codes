#include<bits/stdc++.h> 
using namespace std;
bool table[105];
int main(){
	int n,m;
	cin>>n>>m;
	int a,data;
	memset(table,0,sizeof(table));
	for(int i=0;i<n;i++){
		cin>>a;
		for(int j=0;j<a;j++){
			cin>>data;
			table[data]=true;
		}
	}
	for(int i=1;i<=m;i++){
		if(!table[i]){
			cout<<"NO"<<endl;
			return 0; 
		} 
	}
	cout<<"YES"<<endl;
}