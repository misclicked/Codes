#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	string s;
	while(true){
		cin>>ws;getline(cin,s);
		if(s=="#")return 0;
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]==' ')continue;
			ans+=(s[i]-'A'+1)*(i+1);
		}
		cout<<ans<<endl;
	}
}

