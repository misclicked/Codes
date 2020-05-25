#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long int ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	int n;
	int res[1111];
	cin>>n;
	for(int i=0;i<n;i++)cin>>res[i];
	int pas=res[1]-res[0];
	bool is=true;
	for(int i=2;i<n;i++){
		if(res[i]-res[i-1]!=pas)is=false;
	}
	if(!is)pas=0;
	cout<<res[n-1]+pas<<endl;
}
