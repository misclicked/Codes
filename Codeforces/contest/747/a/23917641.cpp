#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	ll m=sqrt(n);
	for(int i=0;;i++){
		if(n%(m+i)==0){
			cout<<min((m+i),n/(m+i))<<" "<<max((m+i),n/(m+i))<<endl;
			return 0;
		}
		if(n%(m-i)==0){
			cout<<min((m-i),n/(m-i))<<" "<<max((m-i),n/(m-i))<<endl;
			return 0;
		}
	}
}