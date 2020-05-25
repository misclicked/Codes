#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int msum=0;
	int nsum=0;
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		if(input<=0){
			msum+=input;
		}else{
			nsum+=input;
		}
	}
	cout<<nsum-msum<<endl;
}