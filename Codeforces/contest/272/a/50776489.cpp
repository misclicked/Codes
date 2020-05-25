#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	int n;
	cin>>n;
	int total=0;
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		total+=input;
	}
	int ans=0;
	for(int i=1;i<=5;i++){
		if(((total+i)%(n+1))!=1){
			ans++;
		}
	}
	cout<<ans<<endl;
}
