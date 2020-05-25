#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,char> pic;
typedef vector<pic> vpic;
typedef vector<pll> vll;
/*
aaab
aabba
abbaba
abbbbaa
bbabbbaa
bbbbabbaa
bbbbbbabaa
bbbbbbbbaaa

aaab
aabba
abbaba
bbababa
bbbbaaba
bbbbabbaa
bbbbbbabaa
bbbbbbbbaaa

abaab
bbaaab
bbaabba
bbabbaba
bbbbababa
bbbbbbaaba
bbbbbbabbaa
bbbbbbbbabaa
bbbbbbbbbbaaa

aaaaabaabababaaaaaba
aaaaab
aaaaaaab
*/
ll mod = 1e9 + 7;
ll modpow(ll a,ll b){
	ll here = 1, base = a;
	while(b){
		if(b&1) here *= base%mod;
		here %= mod;
		base *= base%mod;
		base %= mod;
		b >>= 1; 
	}
	return here%mod;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	string input;
	cin>>input;
	ll ans=0,a=0;
	for(int i=0;i<input.length();i++){
		if(input[i]=='a'){
			a++;
		}else{
			ans+=(modpow(2,a)-1)%mod;
		}
	}
	cout<<ans%mod<<endl;
}


