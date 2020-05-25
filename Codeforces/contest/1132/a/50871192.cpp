#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	bool ok=true;
	if(a!=d)ok=false;
	if(a==0&&d==0&&c!=0)ok=false;
	cout<<(ok?1:0)<<endl;
} 