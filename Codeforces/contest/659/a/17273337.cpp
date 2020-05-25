#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int ans=a+b+n*(abs(a+b)/n+1);
	cout<< ((ans%n==0)?n:ans%n) <<endl;
} 