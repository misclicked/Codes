#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,x,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&x,&a,&b);
		if(b<a)swap(a,b); 
		int maxe=a-1+n-b;
		printf("%d\n",min(maxe,x)+b-a);
	}
}