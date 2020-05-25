#include<bits/stdc++.h> 
using namespace std;
int mape[55];
int out[55];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n;
	bool flag=true;
	cin>>n;
	int input;
	for(int i=0;i<n;i++){
		memset(mape,0,sizeof(mape));
		for(int j=0;j<n;j++){
			cin>>input;
			mape[input]++;
		}
		int now,mx=0;
		for(int j=1;j<=n;j++){
			if(mape[j]>mx){
				now=j;
				mx=mape[j];
			}
		}
		if(mx==1){
			if(flag){
				out[i]=n;
				flag=false;
			}else{
				out[i]=n-1;
			}
		}else{
			out[i]=now;
		}
	}
	cout<<out[0]; 
	for(int i=1;i<n;i++)
		cout<<" "<<out[i];
	cout<<endl;
	return 0;
}