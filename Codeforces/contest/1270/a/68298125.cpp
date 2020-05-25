#include<iostream>
using std::cin;
main(){
	int t,a,b,A,B,d;
	cin>>t;
	while(t--){
		cin>>a>>a>>b;
		A=B=0;
		while(a--){
			cin>>d;
			A=A>d?A:d;
		}
		while(b--){
			cin>>d;
			B=B>d?B:d;
		}
		puts(A>B?"YES":"NO");
	}
}