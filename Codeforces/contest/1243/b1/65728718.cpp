#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	int n;
	string a,b;
	while(k--){
		cin>>n;
		cin>>a>>b;
		int difcnt=0,difa,difb;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				difcnt++;
				if(difcnt==1)difa=i;
				if(difcnt==2)difb=i; 
			}
		}
		if(difcnt==0){
			cout<<"Yes"<<endl;
		}else if(difcnt==2){
			if(a[difa]==a[difb]&&b[difb]==b[difa]){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}
}