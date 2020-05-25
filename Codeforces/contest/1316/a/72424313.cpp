#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll sum=0;
		for(int i=0;i<n;i++){
			int data;
			cin>>data;
			sum+=data;
		}
		cout<<min(sum,(ll)m)<<endl;		
	}
} 