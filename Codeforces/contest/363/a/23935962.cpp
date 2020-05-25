#include<bits/stdc++.h>
using namespace std;
int main(){
	string input;
	cin>>input;
	for(int i=input.size()-1;i>=0;i--){
		int n=input[i]-'0';
		if(n>=5){
			n-=5;
			cout<<"-O|";
		}else{
			cout<<"O-|";
		}
		for(int j=0;j<n;j++)
			cout<<'O';
		cout<<'-';
		n=5-n-1;
		for(int j=0;j<n;j++)
			cout<<'O';
		cout<<endl;
	}
}