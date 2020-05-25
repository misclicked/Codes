#include<bits/stdc++.h>
using namespace std;
namespace IO{
	char ss[1<<17],*A=ss,*B=ss;
	inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
	template<class T>inline void sd(T&x){
		char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45){y=-1;}x=c-48;
		while(c=gc(),47<c&&c<58){x=x*10+c-48;}x*=y;
	}
}
using namespace IO;
int main(){
	int n;
	sd(n);
	while(n--){
		int a,b;
		sd(a);sd(b);
		if(__gcd(a,b)==1){
			puts("Finite");
		}else{
			puts("Infinite");
		}
	} 
}