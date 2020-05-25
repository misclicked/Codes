#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	vector<ll> primes;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			primes.push_back(i);
			while(n%i==0)n/=i;	
		}
	}
	if(n!=1)primes.push_back(n);
	if(primes.size()==1){
		cout<<primes[0]<<endl;
	}else{
		cout<<1<<endl;
	}
}