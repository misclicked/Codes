#include<iostream>
using namespace std;
main(){
	int i,j,n,k,d,a,b,A,B;
	cin>>n>>k;
	A=B=a=b=0; 
	for(i=1;i<=k+1;i++){
		cout<<"? ";
		for(j=1;j<=k+1;j++)if(i!=j)cout<<j<<" ";cin>>d>>d;
		if(!A||A==d)A=d,a++;else if(!B||B==d)B=d,b++;
	}
	cout<<"! "<<(A>B?a:b)<<endl;
}