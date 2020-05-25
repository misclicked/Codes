#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ll> vl;
int main(){
	int n;
	cin>>n;
	ll tt;
	int ber,ser,bi,si;
	tt=0;
	ber=ser=0;
	bi=si=-1;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		tt+=(a-b);
		if((a-b)>ber){
			ber=(a-b);
			bi=i;
		}
		if((b-a)>ser){
			ser=(b-a);
			si=i;
		}
	}
	if((si==-1)||(bi==-1)){
		cout<<0<<endl;
		return 0;
	}
	if(tt==0){
		if(ber>=ser){
			cout<<bi+1<<endl;
		}else{
			cout<<si+1<<endl;
		}
		return 0;
	}
	if(abs(tt+ser*2)<abs(tt-ber*2)){
		cout<<bi+1<<endl;
	}else{
		cout<<si+1<<endl;
	}
}
