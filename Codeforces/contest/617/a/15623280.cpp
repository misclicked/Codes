#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=5;i>=1;i--){
		while((n-i)>=0){
			n-=i;
			ans++;
		}
		if(n==0)
			break;
	}
	cout<<ans<<endl;
} 