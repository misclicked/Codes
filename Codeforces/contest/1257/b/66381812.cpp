#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(a==1&&b==1)cout<<"YES"<<endl;
		else if(a==1&&b!=1)cout<<"NO"<<endl;
		else if(a<=3&&b>3)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}