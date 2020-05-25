#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;;i++){
		if(n%i==0){
			int x=i*k;
			for(int j=x;j<x+k;j++){
				if(((j/k)*(j%k))==n){
					cout<<j<<endl;
					return 0;
				}
			}
		}
	}
}
