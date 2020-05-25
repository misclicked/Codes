#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> a,b;

int main() {
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        ll now=3,ans=0;
        for(ll i=1;i<=n/2;i++){
        	//cout<<ans<<endl;
        	ans+=i*(now*now-(now-2)*(now-2));
        	//cout<<i<<" "<<(now*now-(now-2)*(now-2))<<endl;
        	now+=2;
		}
		cout<<ans<<endl;
    }
}
