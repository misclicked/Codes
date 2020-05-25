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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	ll n;
	cin>>n;
	vector<ll> vec;
	ll data;
	for(int i=0;i<n;i++){
		cin>>data;
		vec.push_back(data);
	} 
	sort(vec.begin(),vec.end(),greater<ll>());
	for(int i=2;i<n;i++){
		if(vec[i]+vec[i-1]>vec[i-2]){
			cout<<"YES"<<endl;
			exit(0);
		}
	}
	cout<<"NO"<<endl;
}


