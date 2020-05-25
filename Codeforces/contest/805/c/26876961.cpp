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
1 11
2 10
3 9
4 8
5 7
6
*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		exit(0); 
	} 
	cout<<ceil(n/2.0)-1<<endl;
}


