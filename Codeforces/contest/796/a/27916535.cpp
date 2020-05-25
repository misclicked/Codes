#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,char> plc;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	vl vec;
	ll n,m,k,data;
	cin>>n>>m>>k;
	ll now=1;
	for(int i=0;i<n*2;i++){
		vec.push_back(0);
	}
	for(int i=0;i<n;i++){
		cin>>data;
		vec.push_back(data);
	}
	for(int i=0;i<n*2;i++){
		vec.push_back(0);
	}
	for(double i=1.0;i<n*2;i+=0.5){
		ll here = vec[(m+((ll)i)*now)+n*2-1];
		//cout<<here<<endl;
		if(here<=k&&here!=0){
			cout<<((ll)i)*10<<endl;
			return 0;
		}
		now*=-1;
	}
}