#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
void solve(){
	if(a==0 or b==0){
		return;
	}else if(a>=2*b){
		a=a%(2*b);
		solve();
	}else if(b>=2*a){
		b=b%(2*a);
		solve(); 
	}else{
		return;
	}
}
int main(){
	cin>>a>>b;
	solve();
	cout<<a<<" "<<b<<endl;
}