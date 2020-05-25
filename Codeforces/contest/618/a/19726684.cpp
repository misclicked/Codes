#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	bitset<500> b(n);
	bool flag=false;
	for(int i=500;i>=0;i--){
		if(b[i]){
			if(flag)
				cout<<" ";
			cout<<i+1;
			flag=true;
		}
	}
}