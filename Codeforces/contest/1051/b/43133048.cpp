#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll; 
int main(){
	ll l,r;
	scanf("%I64d %I64d",&l,&r);
	puts("YES");
	for(ll i=l;i<=r;i+=2){
		printf("%I64d %I64d\n",i,i+1);
	}
	
}