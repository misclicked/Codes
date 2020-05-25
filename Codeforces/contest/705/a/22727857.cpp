#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,N;
	cin>>N;
	n=N;
	cout<<"I hate";
	while(n>1){
		if(n%2!=(N%2))
			cout<<" that I hate";
		else
			cout<<" that I love"; 
		n--;
	}
	cout<<" it"<<endl;
} 