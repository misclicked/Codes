#include<iostream>
using namespace std;
main(){
	int t,k,i,a,b,n;
	cin>>t;
	while(t--){
		cin>>k;
		n=0,i=1;
		cin>>a;
		while(i++<k){
			cin>>b;
			n=abs(a-b)>1?i:n,a=b;
		}
		if(n)printf("YES %d %d ",n-1,n);else puts("NO");
	}
}