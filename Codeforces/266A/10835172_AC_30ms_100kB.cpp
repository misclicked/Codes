#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,now,ans;
	char pre;
	string input;
	cin>>n;
	cin>>input;
	pre=input[0];
	now=0;
	ans=0;
	for(int i=1;i<n;i++){
		if(input[i]==pre){
			now++;
		}else{
			ans=max(ans,now);
		}
		pre=input[i];
	}
	ans=max(ans,now);
	
	cout<<ans<<endl;
}