#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007ll
int main(){
	ll u,n;
	u=n=0;
	ll ans=1;
	ll f0,f1,nxt;
	f0=0,f1=1;
	char c;
	while(true){
		if(~(c=getchar())){
			switch(c){
				case 'u':
					if(n){
						ans*=f1;
						ans=ans%MOD;
						f0=0,f1=1;
						u=n=0;
					}
					nxt=(f0+f1)%MOD;
					f0=f1;
					f1=nxt;
					u++;
					break;
				case 'n':
					if(u){
						ans*=f1;
						ans=ans%MOD;
						f0=0,f1=1;
						u=n=0;
					}
					nxt=(f0+f1)%MOD;
					f0=f1;
					f1=nxt;
					n++;
					break;
				case 'm':
				case 'w':
					ans*=0;
				default:
					if(u||n)ans*=f1;
					ans=ans%MOD;
					f0=0,f1=1;
					u=n=0;
			}
		}else{
			if(u||n)ans*=f1;
			ans=ans%MOD;
			break;
		}
	}
	cout<<ans<<endl;
}