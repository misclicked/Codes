#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b,c,r;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>r;
		int L,R;
		L=c-r;
		R=c+r;
		if(a>b)swap(a,b); 
		if(a<=L&&R<=b){
			cout<<b-a-(R-L)<<endl;
		}else if(L<=a&&a<=R&&R<=b){
			cout<<b-a-(R-a)<<endl; 
		}else if(a<=L&&L<=b&&b<=R){
			cout<<b-a-(b-L)<<endl;
		}else if(L<=a&&b<=R){
			cout<<0<<endl;
		}else{
			cout<<b-a<<endl;
		}
	} 
} 