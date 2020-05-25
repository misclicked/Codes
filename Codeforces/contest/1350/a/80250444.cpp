#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		if(n&1){
			bool ok=false;
			for(int i=2;i*i<=n;i++){
				if(n%i==0){
					ok=true;
					n+=i;
					break;
				}
			}
			if(!ok)n+=n;
			k--;
		}
		cout<<n+k*2<<endl;
	}
}
