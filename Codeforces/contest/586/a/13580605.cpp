#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
int main(){
	using namespace std;
	int n;
	cin>>n;
	int input[111];
	int pair;
	int sum;
	int first=999;
	int last=-999;
	for(int i=1;i<=n;i++){
		cin>>input[i];
		if(input[i]==1)
			first=min(first,i);
}
	if(first==999){
		cout<<"0";
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(input[i]==1)
			last=max(last,i);
	}
	pair=first;
	sum=last-first+1;
	//cout<<first<<endl<<last<<endl;
	//cout<<sum<<endl;
	for(int i=first;i<=last;i++){
		if(input[i]==1){
			if(i-pair>=3){
				//cout<<i<<endl<<pair<<endl;
				sum=sum-(i-pair-1);
			}
		pair=i;
		//cout<<pair<<endl;
		}		
	}
	cout<<sum;
}
