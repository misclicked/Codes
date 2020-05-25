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
	string a,b;
	cin>>a>>b;
	if(a==b){
		cout<<"-1"<<endl;
	}else{
		cout<<max(a.length(),b.length())<<endl; 
	}
}


