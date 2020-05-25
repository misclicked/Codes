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
	int T,n,m;
	string input;
	cin>>input;
	int cnt=0;
	int MAX=0;
	for(int i=0;i<input.length();i++){
		cnt++;
		char c=input[i];
		if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y'){
			MAX=max(MAX,cnt);
			cnt=0;
		}
		if(i==input.length()-1){
			MAX=max(MAX,cnt+1);
			cnt=0;
		}
	}
	cout<<MAX<<endl;
}