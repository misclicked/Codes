#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;
	cin>>s;
	int cnt=0;
	char now='b';
	bool flag=s[0]=='a';
	for(int i=1;i<s.length();i++){
		if((now>=s[i])&&flag){
			cnt++;
			s[i]=now++;
		}
		if(s[i]=='a')flag=true;
		if(cnt==25)break;
	}
	if(cnt==25){
		cout<<s<<endl;
	}else{
		cout<<-1<<endl;
	}
}