#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
	int n,m;
	cin>>n>>m;
	int now=n;
	for(int i=0;i<=10;i++){
		if(now%10==m||now%10==0){
			cout<<i+1<<endl;
			return 0;
		}
		now+=n;
	}
}