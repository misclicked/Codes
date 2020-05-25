#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	string password;
	cin>>password;
	int n;
	cin>>n;
	bool ew,sw;
	ew=sw=false;
	for(int i=0;i<n;i++){
		string tmp;
		cin>>tmp;
		if(tmp[0]==password[1])
			ew=true;
		if(tmp[1]==password[0])
			sw=true;
		if(tmp==password)
			ew=true,sw=true;
		if(ew&&sw){
			cout<<"YES"<<endl;
			exit(0);
		}
	}
	cout<<"NO"<<endl;
}