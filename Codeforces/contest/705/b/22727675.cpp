#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool now=true;
	while(n--){
		int data;
		cin>>data;
		if(data%2==0){
			now=!now;
		}
		cout<<(now?2:1)<<endl;
	}
}